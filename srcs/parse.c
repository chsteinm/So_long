/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 03:47:15 by chrstein          #+#    #+#             */
/*   Updated: 2024/02/16 03:48:00 by chrstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_rectangle(t_map *map)
{
	int	i;

	map->x = ft_strlen(map->map[0]) - 1;
	map->y = 0;
	while (map->map[++map->y])
		if (ft_strlen(map->map[map->y]) - 1 != map->x)
			return (ft_printf("Map not rectangular\n"), 0);
	map->y--;
	i = -1;
	while (map->map[0][++i])
		if (map->map[0][i] != '1')
			return (ft_printf("Map not surrounded by walls\n", 0));
	i = -1;
	while (map->map[0][++i])
		if (map->map[map->y][i] != '1')
			return (ft_printf("Map not surrounded by walls\n", 0));
	i = -1;
	while (map->map[++i])
		if (map->map[i][0] != '1')
			return (ft_printf("Map not surrounded by walls\n", 0));
	i = -1;
	while (map->map[++i])
		if (map->map[i][map->x] != '1')
			return (ft_printf("Map not surrounded by walls\n", 0));
	return (1);
}

int	check_valid_char(char c)
{
	if (c != 'P' && \
			c != 'E' && \
			c != 'C' && \
			c != '1' && \
			c != '0' && \
			c != '\n')
		return (0);
	else
		return (1);
}

int	check_nbrs(t_map *map)
{
	int	start;
	int	exit;
	int	i;

	map->nb_collect = 0;
	start = 0;
	exit = 0;
	i = -1;
	while (map->one_line_map[++i])
	{
		if (map->one_line_map[i] == 'C')
			map->nb_collect++;
		else if (map->one_line_map[i] == 'P')
			start++;
		else if (map->one_line_map[i] == 'E')
			exit++;
		if (!check_valid_char(map->one_line_map[i]))
			return (ft_printf("Invalid char\n"), 0);
	}
	if (!(start == 1 && exit == 1 && map->nb_collect))
		return (ft_printf("Invalid number of E, P or C\n"), 0);
	return (1);
}

void	fill_P_pos(t_map *map)
{
	map->P_y = 0;
	while (map->map[++map->P_y])
	{
		map->P_x = 0;
		while (map->map[map->P_y][++map->P_x])
			if (map->map[map->P_y][map->P_x] == 'P')
				return ;
	}
}

int	parse(t_map *map, char *path)
{
	int		fd;
	char	*tmp_ptr;
	char	*next_line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_printf("%s: ", path), perror(""), 0);
	next_line = get_next_line(fd);
	if (!next_line || !*next_line)
		return (free(next_line), ft_printf("Error\n"), 0);
	map->one_line_map = next_line;
	while (1)
	{
		tmp_ptr = map->one_line_map;
		next_line = get_next_line(fd);
		if (!next_line)
			break ;
		map->one_line_map = ft_strjoin(tmp_ptr, next_line);
		free(tmp_ptr);
		free(next_line);
	}
	close(fd);
	map->map = ft_split(map->one_line_map, '\n');
	fill_P_pos(map);
	return (check_rectangle(map) && check_nbrs(map) && check_win(*map));
}
