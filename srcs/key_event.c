/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 16:12:41 by jnoh              #+#    #+#             */
/*   Updated: 2022/09/02 13:47:49 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../includes/so_long.h"
#include "../libft/libft.h"

static void	check_collectable_door(t_game *game)
{
	if (game->mapline[game->y * game->wide + game->x] == 'C')
		game->mapline[game->y * game->wide + game->x] = '0';
	if (game->mapline[game->y * game->wide + game->x] == 'E')
	{
		if (ft_strchr(game->mapline, 'C') == 0)
			game_win(game);
	}
}

void	press_w(t_game *game)
{
	if (game->mapline[(game->y - 1) * game->wide + game->x] != '1')
	{
		game->y = game->y - 1;
		game->cnt++;
		check_collectable_door(game);
		map_rander(game);
		print_moving_cnt(game);
	}
}

void	press_a(t_game *game)
{
	if (game->mapline[(game->y) * game->wide + game->x - 1] != '1')
	{
		game->x = game->x - 1;
		game->cnt++;
		check_collectable_door(game);
		map_rander(game);
		print_moving_cnt(game);
	}
}

void	press_s(t_game *game)
{
	if (game->mapline[(game->y + 1) * game->wide + game->x] != '1')
	{
		game->y = game->y + 1;
		game->cnt++;
		check_collectable_door(game);
		map_rander(game);
		print_moving_cnt(game);
	}
}

void	press_d(t_game *game)
{
	if (game->mapline[(game->y) * game->wide + game->x + 1] != '1')
	{
		game->x = game->x + 1;
		game->cnt++;
		check_collectable_door(game);
		map_rander(game);
		print_moving_cnt(game);
	}
}
