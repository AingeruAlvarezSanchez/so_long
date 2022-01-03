/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarez <aalvarez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 11:34:40 by aalvarez          #+#    #+#             */
/*   Updated: 2021/08/16 15:40:00 by aalvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx_opengl_20191021/mlx.h"

void	ft_closemap_error(void)
{
	printf("Error\nThe map needs to be closed on each side");
	exit (0);
}

void	invalid_walls_error(t_gst *gst)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < gst->map.y - 1)
	{
		while (x < gst->map.x - 1)
		{
			if (gst->map.buff[0][x] != '1')
				ft_closemap_error();
			if (gst->map.buff[y][0] != '1')
				ft_closemap_error();
			if (gst->map.buff[gst->map.y - 1][x] != '1')
				ft_closemap_error();
			if (gst->map.buff[y][gst->map.x - 2] != '1')
				ft_closemap_error();
			x++;
		}
		y++;
	}
}

void	ft_error_rectangle(void)
{
	printf("Error\nMap is not a rectangle, try again");
	exit (0);
}
