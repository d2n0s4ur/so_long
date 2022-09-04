/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 12:16:12 by jnoh              #+#    #+#             */
/*   Updated: 2022/09/03 13:17:29 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>

# define X_EVENT_KEY_EXIT		17
# define X_EVENT_KEY_RELEASE	3

# define KEY_W					13
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2

# define KEY_ESC				53

typedef struct s_game {
	void	*mlx_ptr;
	void	*win_ptr;
	int		cnt;
	int		height;
	int		wide;
	int		x;
	int		y;
	char	*mapline;
	void	*img0;
	void	*imgp;
	void	*imgc;
	void	*imge;
	void	*img1;
}	t_game;

void	map_read(char *filename, t_game *game);
void	errormsg(char *str, char *errstr);
void	map_verify(t_game *game);
void	map_draw(t_game *game);
void	free_game(t_game *game);
void	img_load(t_game *game);
void	map_rander(t_game *game);
void	press_w(t_game *game);
void	press_a(t_game *game);
void	press_s(t_game *game);
void	press_d(t_game *game);
void	game_win(t_game *game);
void	print_moving_cnt(t_game *game);

#endif