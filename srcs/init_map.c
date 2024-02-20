#include "../includes/so_long.h"

void	draw_map(void *mlx_ptr, void *win_ptr, t_data *data)
{
	int	x;
	int	y;
	int	tile_size;

	tile_size = 64;
	y = -1;
	while (++y <= data->map.y)
	{
		x = -1;
		while (++x <= data->map.x)
		{
			if (data->map.map[y][x] == '1')
				mlx_put_image_to_window(mlx_ptr, win_ptr, data->pic.wall, x * tile_size, y * tile_size);
			else if ((x + y) % 2)
				mlx_put_image_to_window(mlx_ptr, win_ptr, data->pic.floor1, x * tile_size, y * tile_size);
			else
				mlx_put_image_to_window(mlx_ptr, win_ptr, data->pic.floor2, x * tile_size, y * tile_size);
		}
	}
}

int	init_xpm(t_pic *pic, void *mlx_ptr)
{
	data->pic.wall = mlx_xpm_file_to_image(data->mlx, \
	"./Ressources/Pics/wall.xpm", &data->pic.img_width, &data->pic.img_height);
	if (data->pic.wall == NULL)
		return (0);
	data->pic.floor1 = mlx_xpm_file_to_image(data->mlx, \
	"./Ressources/Pics/floor1.xpm", &data->pic.img_width, &data->pic.img_height);
	if (data->pic.floor1 == NULL)
		return (0);
	data->pic.floor2 = mlx_xpm_file_to_image(data->mlx, \
	"./Ressources/Pics/floor2.xpm", &data->pic.img_width, &data->pic.img_height);
	if (data->pic.floor2 == NULL)
		return (0);
	data->pic.player = mlx_xpm_file_to_image(data->mlx, \
	"./Ressources/Pics/player.xpm", &data->pic.img_width, &data->pic.img_height);
	if (data->pic.player == NULL)
		return (0);
	data->pic.exit = mlx_xpm_file_to_image(data->mlx, \
	"./Ressources/Pics/exit.xpm", &data->pic.img_width, &data->pic.img_height);
	if (data->pic.exit == NULL)
		return (0);
	data->pic.collect = mlx_xpm_file_to_image(data->mlx, \
	"./Ressources/Pics/collect.xpm", &data->pic.img_width, &data->pic.img_height);
	if (data->pic.collect == NULL)
		return (0);
	return (1);
}