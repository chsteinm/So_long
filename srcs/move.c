#include "../includes/so_long.h"

void	move_a(t_map *map, t_data *data)
{
	if (map->map[map->P_y][map->P_x - 1] == '1')
		return ;
	if (map->map[map->P_y][map->P_x - 1] == 'C')
		map->nb_collect--
	map->map[map->P_y][map->P_x] = '0';
	map->P_x--;
	map->map[map->P_y][map->P_x] = 'P';
	draw_map(data->mlx, data->mlx_win, data);
	ft_printf("\033[A\033[KMove : %d\n", ++data->count_move);
}

void	move_d(t_map *map, t_data *data)
{
	if (map->map[map->P_y][map->P_x + 1] == '1')
		return ;
	if (map->map[map->P_y][map->P_x - 1] == 'C')
		map->nb_collect--
	map->map[map->P_y][map->P_x] = '0';
	map->P_x++;
	map->map[map->P_y][map->P_x] = 'P';
	draw_map(data->mlx, data->mlx_win, data);
	ft_printf("\033[A\033[KMove : %d\n", ++data->count_move);
}

void	move_s(t_map *map, t_data *data)
{
	if (map->map[map->P_y + 1][map->P_x] == '1')
		return ;
	if (map->map[map->P_y][map->P_x - 1] == 'C')
		map->nb_collect--
	map->map[map->P_y][map->P_x] = '0';
	map->P_y++;
	map->map[map->P_y][map->P_x] = 'P';
	draw_map(data->mlx, data->mlx_win, data);
	ft_printf("\033[A\033[KMove : %d\n", ++data->count_move);
}

void	move_w(t_map *map, t_data *data)
{
	if (map->map[map->P_y - 1][map->P_x] == '1')
		return ;
	if (map->map[map->P_y][map->P_x - 1] == 'C')
		map->nb_collect--
	map->map[map->P_y][map->P_x] = '0';
	map->P_y--;
	map->map[map->P_y][map->P_x] = 'P';
	draw_map(data->mlx, data->mlx_win, data);
	ft_printf("\033[A\033[KMove : %d\n", ++data->count_move);
}

