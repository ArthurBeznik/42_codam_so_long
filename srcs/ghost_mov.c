/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ghost_mov.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 13:33:38 by abeznik       #+#    #+#                 */
/*   Updated: 2021/12/08 17:19:02 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h> // printf

void	ghost_move_right(t_img *img)
{
	if (!check_ifWall(img, img->ghostX + 1, img->ghostY))
	{
		build_image("./images/xpm/ghost.xpm", img, img->ghostX + 1, \
			img->ghostY);
		img->ghostX = img->ghostX + 1;
		build_image("./images/xpm/pill.xpm", img, img->ghostX - 1, \
			img->ghostY);
	}
}

void	ghost_move_left(t_img *img)
{
	if (!check_ifWall(img, img->ghostX - 1, img->ghostY))
	{
		build_image("./images/xpm/ghost.xpm", img, img->ghostX - 1, \
			img->ghostY);
		img->ghostX = img->ghostX - 1;
		build_image("./images/xpm/pill.xpm", img, img->ghostX + 1, \
			img->ghostY);
	}
}

void	ghost_move_up(t_img *img)
{
	if (!check_ifWall(img, img->ghostX, img->ghostY - 1))
	{
		build_image("./images/xpm/ghost.xpm", img, img->ghostX, \
			img->ghostY - 1);
		img->ghostY = img->ghostY - 1;
		build_image("./images/xpm/pill.xpm", img, img->ghostX, \
			img->ghostY + 1);
	}
}

void	ghost_move_down(t_img *img)
{
	if (!check_ifWall(img, img->ghostX, img->ghostY + 1))
	{
		build_image("./images/xpm/ghost.xpm", img, img->ghostX, \
			img->ghostY + 1);
		img->ghostY = img->ghostY + 1;
		build_image("./images/xpm/pill.xpm", img, img->ghostX, \
			img->ghostY - 1);
	}
}
