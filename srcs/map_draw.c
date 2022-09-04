/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 11:17:54 by jnoh              #+#    #+#             */
/*   Updated: 2022/09/03 12:51:09 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/so_long.h"
#include "../mlx/mlx.h"

static void	map_draw_img(t_game *game, int x, int y, char type)
{
	if (type == '0' || type == 'C' || type == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->img0, x * 64, y * 64);
	if (type == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->img1, x * 64, y * 64);
	if (type == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->imgc, x * 64, y * 64);
	if (type == 'P')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->imgp, x * 64, y * 64);
		game->x = x;
		game->y = y;
	}
	if (type == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->imge, x * 64, y * 64);
}

void	map_draw(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	while (i < game->height)
	{
		j = 0;
		while (j < game->wide)
		{
			map_draw_img(game, j, i, game->mapline[i * game->wide + j]);
			j++;
		}
		i++;
	}
}

void	map_rander(t_game *game)
{
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	map_draw(game);
	map_draw_img(game, game->x, game->y, 'P');
}
