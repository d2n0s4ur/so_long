/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:49:09 by jnoh              #+#    #+#             */
/*   Updated: 2022/09/03 13:10:06 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/so_long.h"

static void	check_rectangular(t_game *game)
{
	if (ft_strlen(game->mapline) != (size_t)(game->wide * game->height))
	{
		errormsg("Error\n", "Map is not rectangular.\n");
		free_game(game);
		exit(-1);
	}
}

static void	check_walls(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->wide)
	{
		if (game->mapline[i] != '1' || \
		game->mapline[game->wide * (game->height - 1) + i] != '1')
		{
			errormsg("Error\n", "Map does not surround with walls.\n");
			free_game(game);
			exit(-1);
		}
	}
	i = -1;
	while (++i < game->height)
	{
		if (game->mapline[i * game->wide] != '1' || \
		game->mapline[(i + 1) * game->wide - 1] != '1')
		{
			errormsg("Error\n", "Map does not surround with walls.\n");
			free_game(game);
			exit(-1);
		}
	}
}

static int	check_str_cnt(char *str, char c)
{
	int		cnt;
	size_t	i;

	cnt = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			cnt++;
		i++;
	}
	return (cnt);
}

static void	check_comp(t_game *game)
{
	if (check_str_cnt(game->mapline, 'C') == 0)
	{
		errormsg("Error\n", "Collectible is not exist.\n");
		free_game(game);
		exit(-1);
	}
	if (check_str_cnt(game->mapline, 'E') == 0)
	{
		errormsg("Error\n", "Exit is not exist.\n");
		free_game(game);
		exit(-1);
	}
	if (check_str_cnt(game->mapline, 'P') != 1)
	{
		errormsg("Error\n", \
		"Player's starting position is not exist or more than one.\n");
		free_game(game);
		exit(-1);
	}
}

void	map_verify(t_game *game)
{
	int		loc;
	char	*person_loc;

	check_rectangular(game);
	check_walls(game);
	check_comp(game);
	person_loc = ft_strchr(game->mapline, 'P');
	loc = person_loc - game->mapline;
	game->x = loc % game->wide;
	game->y = loc / game->wide;
	*person_loc = '0';
}
