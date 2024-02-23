#include "../includes/so_long.h"

void	move_a(void *mlx_ptr, void *win_ptr, t_map *map, t_data *data)
{
	if (map->map[map->P_y][map->P_x - 1] == '1')
		return ;
	data->count_move++;
	if (map->map[map->P_y][map->P_x - 1] == 'C')
	{
		map->nb_collect--;
		map->map[map->P_y][map->P_x - 1] = '0';
	}
	map->P_x--;
	if (map->map[map->P_y][map->P_x] == 'E' && !map->nb_collect)
	{
		ft_printf("\033[A\033[KYou won with %d moves !\n", data->count_move);
		destroy(data);
	}
	draw_map(data->mlx, data->mlx_win, data);
	mlx_put_image_to_window(mlx_ptr, win_ptr, data->pic.player, map->P_x * 64 + 7, map->P_y * 64 + 7);
	ft_printf("\033[A\033[KMove : %d\n", data->count_move);
}

void	move_d(void *mlx_ptr, void *win_ptr, t_map *map, t_data *data)
{
	if (map->map[map->P_y][map->P_x + 1] == '1')
		return ;
	data->count_move++;
	if (map->map[map->P_y][map->P_x + 1] == 'C')
	{
		map->nb_collect--;
		map->map[map->P_y][map->P_x + 1] = '0';
	}
	map->P_x++;
	if (map->map[map->P_y][map->P_x] == 'E' && !map->nb_collect)
	{
		ft_printf("\033[A\033[KYou won with %d moves !\n", data->count_move);
		destroy(data);
	}
	draw_map(data->mlx, data->mlx_win, data);
	mlx_put_image_to_window(mlx_ptr, win_ptr, data->pic.player, map->P_x * 64 + 7, map->P_y * 64 + 7);
	ft_printf("\033[A\033[KMove : %d\n", data->count_move);
}

void	move_s(void *mlx_ptr, void *win_ptr, t_map *map, t_data *data)
{
	if (map->map[map->P_y + 1][map->P_x] == '1')
		return ;
	data->count_move++;
	if (map->map[map->P_y + 1][map->P_x] == 'C')
	{
		map->nb_collect--;
		map->map[map->P_y + 1][map->P_x] = '0';
	}
	map->P_y++;
	if (map->map[map->P_y][map->P_x] == 'E' && !map->nb_collect)
	{
		ft_printf("\033[A\033[KYou won with %d moves !\n", data->count_move);
		destroy(data);
	}
	draw_map(data->mlx, data->mlx_win, data);
	mlx_put_image_to_window(mlx_ptr, win_ptr, data->pic.player, map->P_x * 64 + 7, map->P_y * 64 + 7);
	ft_printf("\033[A\033[KMove : %d\n", data->count_move);
}

void	move_w(void *mlx_ptr, void *win_ptr, t_map *map, t_data *data)
{
	if (map->map[map->P_y - 1][map->P_x] == '1')
		return ;
	data->count_move++;
	if (map->map[map->P_y - 1][map->P_x] == 'C')
	{
		map->nb_collect--;
		map->map[map->P_y - 1][map->P_x] = '0';
	}
	map->P_y--;
	if (map->map[map->P_y][map->P_x] == 'E' && !map->nb_collect)
	{
		ft_printf("\033[A\033[KYou won with %d moves !\n", data->count_move);
		destroy(data);
	}
	draw_map(data->mlx, data->mlx_win, data);
	mlx_put_image_to_window(mlx_ptr, win_ptr, data->pic.player, map->P_x * 64 + 7, map->P_y * 64 + 7);
	ft_printf("\033[A\033[KMove : %d\n", data->count_move);
}

