/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 12:26:48 by jnoh              #+#    #+#             */
/*   Updated: 2022/09/02 22:18:55 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../includes/so_long.h"
#include "../libft/libft.h"

static int	exit_game(t_game *game)
{
	free_game(game);
	exit(0);
}

static int	key_press_handle(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		press_w(game);
	if (keycode == KEY_A)
		press_a(game);
	if (keycode == KEY_S)
		press_s(game);
	if (keycode == KEY_D)
		press_d(game);
	if (keycode == KEY_ESC)
		exit_game(game);
	return (0);
}

static void	game_setting(t_game *game, char *filename, char *programname)
{
	map_read(filename, game);
	map_verify(game);
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->wide * 64, \
		game->height * 64, programname);
	img_load(game);
	map_rander(game);
	mlx_hook(game->win_ptr, X_EVENT_KEY_RELEASE, 0, &key_press_handle, game);
	mlx_hook(game->win_ptr, X_EVENT_KEY_EXIT, 0, &exit_game, game);
	mlx_loop(game->mlx_ptr);
}

int	main(int argc, char *argv[])
{
	t_game	*game;

	if (argc != 2)
	{
		errormsg("usage: ./so_long <mapfile>", "");
		return (0);
	}
	game = (t_game *)malloc(sizeof(t_game) + 1);
	if (!game)
	{
		errormsg("Error\n", strerror(errno));
		return (0);
	}
	ft_memset(game, 0, sizeof(t_game) + 1);
	game_setting(game, argv[1], argv[0]);
}
