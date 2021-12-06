/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_read.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/21 21:21:29 by abeznik       #+#    #+#                 */
/*   Updated: 2021/10/21 21:21:29 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#include <stdio.h> //printf

/*
** Function to perform checks: length of lines, presence of walls
** and existing at least one E, one C and one P.
*/
static int	perform_checks(char **map, size_t nb_lines, size_t len_line)
{
	if (check_char(map, nb_lines, len_line))
		return (EXIT_FAILURE);
	if (check_len(map, nb_lines, len_line))
		return (EXIT_FAILURE);
	if (check_walls(map, nb_lines, len_line))
		return (EXIT_FAILURE);
	if (check_ecp(map, nb_lines))
		return (EXIT_FAILURE);
	printf("The map contains %zu lines of %zu length.\n", nb_lines, len_line);
	return (EXIT_SUCCESS);
}

/*
** Function to read input file, create a linked list based on the 
** input and perform checks.
*/
int	map_read(t_img *img)
{
	char	**map;
	char	*line;
	size_t	line_len;
	size_t	i;

	line_len = 0;
	i = 0;
	line = get_next_line(img->fd);
	map[i] = line;
	line_len = ft_strlen(line);
	while (line)
	{
		i++;
		line = get_next_line(img->fd);
		map[i] = line;
	}
	img->map = map;
	img->nb_lines = i;
	img->len_line = line_len;
	return (perform_checks(img->map, img->nb_lines, img->len_line));
}
