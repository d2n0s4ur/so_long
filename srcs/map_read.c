/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 12:14:11 by jnoh              #+#    #+#             */
/*   Updated: 2022/09/03 14:22:05 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/so_long.h"

static char	*ft_strjoin_del_newline(char *s1, char *s2)
{
	char	*ret;
	int		offset;

	if (ft_strchr(s2, '\n'))
		offset = -1;
	else
		offset = 0;
	ret = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1 + offset);
	if (!ret)
		return (0);
	ft_memcpy(ret, s1, ft_strlen(s1));
	ft_memcpy(ret + ft_strlen(s1), s2, ft_strlen(s2) + offset);
	ret[ft_strlen(s1) + ft_strlen(s2) + offset] = 0;
	return (ret);
}

static void	map_get_first_line(int fd, t_game *game)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
	{
		errormsg("Error\n", strerror(errno));
		exit (-1);
	}
	game->wide = ft_strlen(line) - 1;
	game->mapline = ft_strjoin_del_newline("", line);
	free(line);
}

static size_t	ft_strlen_without_newline(char	*str)
{
	size_t	i;
	size_t	ret;

	ret = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != '\n')
			ret++;
		i++;
	}
	return (ret);
}

static void	map_get_lines(int fd, t_game *game)
{
	char	*line;
	char	*to_free;

	map_get_first_line(fd, game);
	while (1)
	{
		game->height++;
		line = get_next_line(fd);
		if (!line)
			break ;
		if (ft_strlen_without_newline(line) != (size_t)(game->wide))
		{
			errormsg("Error\n", "Map is not rectangular.\n");
			free(line);
			free_game(game);
			exit(-1);
		}
		to_free = game->mapline;
		game->mapline = ft_strjoin_del_newline(to_free, line);
		free(to_free);
		free(line);
	}
	close(fd);
}

void	map_read(char *filename, t_game *game)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
	{
		errormsg("Error\n", strerror(errno));
		exit (-1);
	}
	map_get_lines(fd, game);
}
