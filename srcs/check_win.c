#include "../includes/so_long.h"

int	rec_check(t_map *cpy, int y, int x, int exit_access)
{
	if (cpy->map[y][x])
	if (!cpy->nb_collect && exit_access)
		return (1);
}

int	check_win(t_map cpy)
{
	int	bool;

	cpy.map = ft_split(cpy.one_line_map, '\n');
	bool = rec_check(&cpy, cpy.P_y, cpy.P_x , 0);

	ft_free_strings(cpy.map);
	return (1);
}