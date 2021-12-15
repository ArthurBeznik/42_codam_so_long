/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/11 17:00:38 by abeznik       #+#    #+#                 */
/*   Updated: 2021/12/11 17:00:38 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#include <unistd.h> // close
#include <stdlib.h> // free
#include <fcntl.h> // open

static int	ft_close(void)
{
	system("leaks so_long");
	exit(EXIT_SUCCESS);
}

static void	check_ber(char *str)
{
	char	**index;
	int		i;

	i = 0;
	index = ft_split(str, '.');
	while (index[i] != NULL)
		i++;
	i = ft_strncmp(index[i - 1], "ber", 3);
	if (i != 0)
	{
		error_msg("\tPlease enter .ber file.\n");
		free(index[1]);
		free(index[0]);
		free(index);
		exit(EXIT_FAILURE);
	}
	free(index[1]);
	free(index[0]);
	free(index);
}

static void	mlx_main(t_img *img)
{
	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, img->len_line * IMG_SIZE, \
		img->nb_lines * IMG_SIZE, "./so_long");
	img->img = mlx_new_image(img->mlx, img->len_line * IMG_SIZE, \
		img->nb_lines * IMG_SIZE);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
		&img->line_length, &img->endian);
	mlx_get_screen_size(img->mlx, &img->sizex, &img->sizey);
	if (img->len_line * IMG_SIZE > img->sizex || \
		img->nb_lines * IMG_SIZE > img->sizey)
	{
		error_msg("\tMap too big for screen.\n");
		exit(EXIT_FAILURE);
	}
	img->consumables = 0;
	img->open_exit = 0;
	build_map(img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_img	img;
	int		ret;

	if (argc < 2)
		return (error_msg("\tNo map entered.\n"));
	if (argc > 2)
		return (error_msg("\tToo many arguments entered.\n"));
	check_ber(argv[1]);
	img.fd1 = open(argv[1], O_RDONLY);
	if (img.fd1 == -1)
		return (error_msg("\tFailed to open the map.\n"));
	img.fd2 = open(argv[1], O_RDONLY);
	if (map_read(&img) != 0)
		exit(EXIT_FAILURE);
	mlx_main(&img);
	mlx_hook(img.win, 2, 1L << 0, key_hook, &img);
	mlx_hook(img.win, 17, 1L << 17, ft_close, &img);
	mlx_loop(img.mlx);
	ret = 0;
	ret = close(img.fd1);
	if (ret == -1)
		return (error_msg("\tFailed to close the map.\n"));
	close(img.fd2);
	return (EXIT_SUCCESS);
}
