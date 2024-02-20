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

typedef struct s_pic
{
	void	*wall;
	void	*floor1;
	void	*floor2;
	void	*player;
	void	*collect;
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
	size_t				P_x;
	size_t				P_y;
}					t_map;

typedef struct s_data
{
	t_map	map;
	void	*mlx;
	void	*mlx_win;
	t_pic	pic;
}					t_data;

int	parse(t_map *map);
int	check_win(t_map cpy);
void	draw_map(void *mlx_ptr, void *win_ptr, t_data *data);

#endif
