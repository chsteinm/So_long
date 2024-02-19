/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 03:46:35 by chrstein          #+#    #+#             */
/*   Updated: 2024/02/16 03:46:51 by chrstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_all(t_data *data)
{
	free(data->map.one_line_map);
	ft_free_strings(data->map.map);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}

int	set_data(t_data *data, char *path)
{
	data->map.map = NULL;
	data->map.one_line_map = NULL;
	data->map.exit_access = 0;
	data->mlx = NULL;
	data->mlx_win = NULL;
	data->pic.wall = NULL;
	data->pic.img_height = 64;
	data->pic.img_width = 64;
	data->map.fd = open(path, O_RDONLY);
	if (data->map.fd == -1)
		return (ft_printf("%s: ", path), perror(""), 0);
	return (1);
}

void draw_map(void *mlx_ptr, void *win_ptr, t_data *data)
{
    size_t x, y;
    int tile_size = 64; // Taille des tuiles de la carte en pixels

    for (y = 0; y <= data->map.y; y++) {
        for (x = 0; x <= data->map.x; x++) {
            // Dessine un carré à la position (x * tile_size, y * tile_size) pour chaque élément de la carte
            if (data->map.map[y][x] == '1') {
                // Dessine un mur
                mlx_put_image_to_window(mlx_ptr, win_ptr, data->pic.wall, x * tile_size, y * tile_size);
            } else {
                // Dessine un chemin
                mlx_pixel_put(mlx_ptr, win_ptr, x * tile_size, y * tile_size, 0x255FFF); // Couleur noire pour les chemins
            }
            // Ajoute d'autres conditions pour les objets collectables, le personnage, etc.
        }
    }
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2 || !set_data(&data, argv[1]) || !parse(&data.map))
		return (free_all(&data), 1);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (free_all(&data), 1);
	data.mlx_win = mlx_new_window(data.mlx, 64 * (1 + data.map.x), 64 * (1 + data.map.y), "m");
	if (!data.mlx_win)
		return (free_all(&data), 1);
	data.pic.wall = mlx_xpm_file_to_image(data.mlx, "./Ressources/Pics/wall.xpm", &data.pic.img_width, &data.pic.img_height);
	if (data.pic.wall == NULL)
		return (free_all(&data), 1); // Gestion de l'erreur si le chargement de l'image échoue
	draw_map(data.mlx, data.mlx_win, &data);
	mlx_loop(data.mlx);
	free_all(&data);
	return (0);
}
