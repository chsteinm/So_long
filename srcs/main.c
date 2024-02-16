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

void	set_data(t_data *data)
{
	data->map.map = NULL;
	data->map.one_line_map = NULL;
}

int	main(int argc, char **argv)
{
	t_data	data;

	set_data(&data);
	if (argc != 2 || !parse(&data.map, argv[1]))
		return (free_all(&data), 1);
	ft_printstrs(data.map.map);
	free_all(&data);
	return (0);
}
