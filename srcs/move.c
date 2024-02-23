#include "../includes/so_long.h"

void	redraw(void *mlx_ptr, void *win_ptr, t_data *data)
{
	int	x;
	int	y;
	int	tile_size;

	tile_size = 64;
	x = data->map.P_x;
	y = data->map.P_y;
	if (data->map.map[y][x] == 'E')
		mlx_put_image_to_window(mlx_ptr, win_ptr, data->pic.exit, x * tile_size, y * tile_size);
	else if ((x + y) % 2)
		mlx_put_image_to_window(mlx_ptr, win_ptr, data->pic.floor1, x * tile_size, y * tile_size);
	else
		mlx_put_image_to_window(mlx_ptr, win_ptr, data->pic.floor2, x * tile_size, y * tile_size);
}

void	move(t_map *map, t_data *data, int new_x, int new_y)
{
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = data->mlx;
	win_ptr = data->mlx_win;
	if (map->map[new_y][new_x] == '1')
		return ;
	data->count_move++;
	if (map->map[new_y][new_x] == 'C')
	{
		map->nb_collect--;
		map->map[new_y][new_x] = '0';
	}
	redraw(data->mlx, data->mlx_win, data);
	map->P_x = new_x;
	map->P_y = new_y;
	if (map->map[map->P_y][map->P_x] == 'E' && !map->nb_collect)
	{
		ft_printf("\033[A\033[KYou won with %d moves !\n", data->count_move);
		destroy(data);
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, data->pic.player, map->P_x * 64 + 7, map->P_y * 64 + 7);
	ft_printf("\033[A\033[KMove : %d\n", data->count_move);
}

// void	move_a(void *mlx_ptr, void *win_ptr, t_map *map, t_data *data)
// {
// 	if (map->map[map->P_y][map->P_x - 1] == '1')
// 		return ;
// 	data->count_move++;
// 	if (map->map[map->P_y][map->P_x - 1] == 'C')
// 	{
// 		map->nb_collect--;
// 		map->map[map->P_y][map->P_x - 1] = '0';
// 	}
// 	redraw(data->mlx, data->mlx_win, data);
// 	map->P_x--;
// 	if (map->map[map->P_y][map->P_x] == 'E' && !map->nb_collect)
// 	{
// 		ft_printf("\033[A\033[KYou won with %d moves !\n", data->count_move);
// 		destroy(data);
// 	}
// 	mlx_put_image_to_window(mlx_ptr, win_ptr, data->pic.player, map->P_x * 64 + 7, map->P_y * 64 + 7);
// 	ft_printf("\033[A\033[KMove : %d\n", data->count_move);
// }

// void	move_d(void *mlx_ptr, void *win_ptr, t_map *map, t_data *data)
// {
// 	if (map->map[map->P_y][map->P_x + 1] == '1')
// 		return ;
// 	data->count_move++;
// 	if (map->map[map->P_y][map->P_x + 1] == 'C')
// 	{
// 		map->nb_collect--;
// 		map->map[map->P_y][map->P_x + 1] = '0';
// 	}
// 	redraw(data->mlx, data->mlx_win, data);
// 	map->P_x++;
// 	if (map->map[map->P_y][map->P_x] == 'E' && !map->nb_collect)
// 	{
// 		ft_printf("\033[A\033[KYou won with %d moves !\n", data->count_move);
// 		destroy(data);
// 	}
// 	mlx_put_image_to_window(mlx_ptr, win_ptr, data->pic.player, map->P_x * 64 + 7, map->P_y * 64 + 7);
// 	ft_printf("\033[A\033[KMove : %d\n", data->count_move);
// }

// void	move_s(void *mlx_ptr, void *win_ptr, t_map *map, t_data *data)
// {
// 	if (map->map[map->P_y + 1][map->P_x] == '1')
// 		return ;
// 	data->count_move++;
// 	if (map->map[map->P_y + 1][map->P_x] == 'C')
// 	{
// 		map->nb_collect--;
// 		map->map[map->P_y + 1][map->P_x] = '0';
// 	}
// 	redraw(data->mlx, data->mlx_win, data);
// 	map->P_y++;
// 	if (map->map[map->P_y][map->P_x] == 'E' && !map->nb_collect)
// 	{
// 		ft_printf("\033[A\033[KYou won with %d moves !\n", data->count_move);
// 		destroy(data);
// 	}
// 	mlx_put_image_to_window(mlx_ptr, win_ptr, data->pic.player, map->P_x * 64 + 7, map->P_y * 64 + 7);
// 	ft_printf("\033[A\033[KMove : %d\n", data->count_move);
// }

// void	move_w(void *mlx_ptr, void *win_ptr, t_map *map, t_data *data)
// {
// 	if (map->map[map->P_y - 1][map->P_x] == '1')
// 		return ;
// 	data->count_move++;
// 	if (map->map[map->P_y - 1][map->P_x] == 'C')
// 	{
// 		map->nb_collect--;
// 		map->map[map->P_y - 1][map->P_x] = '0';
// 	}
// 	redraw(data->mlx, data->mlx_win, data);
// 	map->P_y--;
// 	if (map->map[map->P_y][map->P_x] == 'E' && !map->nb_collect)
// 	{
// 		ft_printf("\033[A\033[KYou won with %d moves !\n", data->count_move);
// 		destroy(data);
// 	}
// 	mlx_put_image_to_window(mlx_ptr, win_ptr, data->pic.player, map->P_x * 64 + 7, map->P_y * 64 + 7);
// 	ft_printf("\033[A\033[KMove : %d\n", data->count_move);
// }

