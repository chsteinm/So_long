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
}

int	set_data(t_data *data, char *path)
{
	data->map.fd = open(path, O_RDONLY);
	if (data->map.fd == -1)
		return (ft_printf("%s: ", path), perror(""), 0);
	data->map.map = NULL;
	data->map.one_line_map = NULL;
	data->map.exit_access = 0;
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2 || !set_data(&data, argv[1]) || !parse(&data.map))
		return (free_all(&data), 1);
	ft_printstrs(data.map.map);
	free_all(&data);
	return (0);
}
