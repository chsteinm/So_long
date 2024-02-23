/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:05:40 by chrstein          #+#    #+#             */
/*   Updated: 2024/02/06 17:23:44 by chrstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "get_next_line.h"
# include "../minilibx-linux/mlx.h"

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>

# define W 119
# define S 115
# define A 97
# define D 100
# define ESC 65307
# define FLOOR1 "Ressources/Pics/floor1.xpm"
# define FLOOR2 "Ressources/Pics/floor2.xpm"
# define WALL "Ressources/Pics/wall.xpm"
# define PLAYER "Ressources/Pics/player.xpm"
# define COLLECT1 "Ressources/Pics/collect1.xpm"
# define COLLECT2 "Ressources/Pics/collect2.xpm"
# define EXIT "Ressources/Pics/exit.xpm"

typedef struct s_pic
{
	void	*wall;
	void	*floor1;
	void	*floor2;
	void	*player;
	void	*collect1;
	void	*collect2;
	void	*exit;
	int		img_width;
	int		img_height;
}					t_pic;

typedef struct s_map
{
	int					x;
	int					y;
	int					nb_collect;
	int					exit_access;
	int					fd;
	char				*one_line_map;
	char				**map;
	int					P_x;
	int					P_y;
}					t_map;

typedef struct s_data
{
	t_map	map;
	void	*mlx;
	void	*mlx_win;
	t_pic	pic;
	size_t	count_move;
}					t_data;

int	parse(t_map *map);
int	check_win(t_map cpy);
void	draw_map(void *mlx_ptr, void *win_ptr, t_data *data);
int	init_xpm(t_pic *pic, void *mlx_ptr);
void	move_a(void *mlx_ptr, void *win_ptr, t_map *map, t_data *data);
void	move_d(void *mlx_ptr, void *win_ptr, t_map *map, t_data *data);
void	move_s(void *mlx_ptr, void *win_ptr, t_map *map, t_data *data);
void	move_w(void *mlx_ptr, void *win_ptr, t_map *map, t_data *data);
int	destroy(t_data *data);

#endif
