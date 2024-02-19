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

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>

typedef struct s_map
{
	size_t				x;
	size_t				y;
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
}					t_data;

int	parse(t_map *map);
int	check_win(t_map cpy);

#endif
