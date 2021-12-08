/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_walls.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/07 14:18:52 by abeznik       #+#    #+#                 */
/*   Updated: 2021/12/08 17:01:32 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#include <stdio.h> //printf

/*
** Function to check if upper and lower lines contain only '1'.
*/
static int	upper_lowerLines(char **tmp, int len_line, int y)
{
	int	x;

	x = 0;
	while (x < len_line)
	{
		if (tmp[y][x] != '1')
			return (error_msg("\tInvalid walls \
				(see upper or lower wall).\n"));
		x++;
	}
	return (success_msg("\tFound surrounding walls.\n"));
}

/*
** Function to check if the map is closed by walls.
*/
int	check_walls(char **map, int nb_lines, int len_line)
{
	char	**tmp;
	int		y;

	y = 0;
	tmp = map;
	while (y < nb_lines)
	{
		if (y == 0 || y == nb_lines - 1)
			return (upper_lowerLines(tmp, len_line, y));
		else
		{
			if (tmp[y][0] != '1' || tmp[y][len_line - 1] != '1')
				return (error_msg("\tInvalid walls (see middle wall).\n"));
		}
		y++;
	}
	return (success_msg("\tFound surrounding walls.\n"));
}
