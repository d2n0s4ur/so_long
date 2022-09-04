/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:12:10 by jnoh              #+#    #+#             */
/*   Updated: 2022/09/03 13:15:53 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/libft.h"
#include "../mlx/mlx.h"

void	print_moving_cnt(t_game *game)
{
	char	*cntstr;

	ft_putstr_fd("Moving Count: ", 1);
	ft_putnbr_fd(game->cnt, 1);
	ft_putstr_fd("\n", 1);
	cntstr = ft_itoa(game->cnt);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 32, 32, 0xFFFFFFFF, cntstr);
	free(cntstr);
}

void	errormsg(char *str, char *errstr)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd(errstr, 2);
	ft_putstr_fd("\n", 2);
}

void	free_game(t_game *game)
{
	if (game->mlx_ptr && game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mapline)
		free(game->mapline);
	free(game);
}

void	img_load(t_game *game)
{
	int	w;
	int	h;

	game->img0 = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./images/img0.xpm", &w, &h);
	game->img1 = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./images/img1.xpm", &w, &h);
	game->imgc = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./images/imgC.xpm", &w, &h);
	game->imge = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./images/imgE.xpm", &w, &h);
	game->imgp = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./images/imgP.xpm", &w, &h);
}

void	game_win(t_game *game)
{
	ft_putstr_fd("Congraturaion!\nResult: ", 1);
	ft_putnbr_fd(game->cnt, 1);
	ft_putstr_fd(" moves.\n", 1);
	free_game(game);
	exit(0);
}
