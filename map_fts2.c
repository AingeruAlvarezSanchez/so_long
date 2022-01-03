/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fts2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarez <aalvarez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 13:05:57 by aalvarez          #+#    #+#             */
/*   Updated: 2021/08/16 14:03:49 by aalvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx_opengl_20191021/mlx.h"

/*This function redraws images whenever you move*/
void	ft_redraw(t_gst *gst, int x, int y)
{
	mlx_put_image_to_window(gst->gvs.m, gst->gvs.w,
		gst->bg.i, x * 50, y * 50);
	if (gst->map.buff[y][x] == 'E')
		mlx_put_image_to_window(gst->gvs.m, gst->gvs.w,
			gst->e.i, x * 50, y * 50);
	if (gst->map.buff[y][x] == '1')
		mlx_put_image_to_window(gst->gvs.m, gst->gvs.w,
			gst->w.i, x * 50, y * 50);
	if (gst->map.buff[y][x] == 'C')
		mlx_put_image_to_window(gst->gvs.m, gst->gvs.w,
			gst->cl.i, x * 50, y * 50);
}

/*Check "ft_redraw"*/
int	redraw_start(t_gst *gst)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	fill_images(gst);
	while (y < gst->map.y)
	{
		x = 0;
		while (x < gst->map.x)
		{
			ft_redraw(gst, x, y);
			x++;
		}
		y++;
	}
	return (1);
}

/*This is only a complementary function
 * that gives every struct and address, so
 * that struct is linked to an image*/
void	fill_images(t_gst *gst)
{
	gst->bg.a = "./sprites/myfloor.xpm";
	gst->bg.i = mlx_xpm_file_to_image(gst->gvs.m,
			gst->bg.a, &gst->bg.w, &gst->bg.h);
	gst->e.a = "./sprites/exit.xpm";
	gst->e.i = mlx_xpm_file_to_image(gst->gvs.m,
			gst->e.a, &gst->e.w, &gst->e.h);
	gst->w.a = "./sprites/barrels.xpm";
	gst->w.i = mlx_xpm_file_to_image(gst->gvs.m,
			gst->w.a, &gst->w.w, &gst->w.h);
	gst->cl.a = "./sprites/collectables.xpm";
	gst->cl.i = mlx_xpm_file_to_image(gst->gvs.m,
			gst->cl.a, &gst->cl.w, &gst->cl.h);
	gst->p.a = "./sprites/player.xpm";
	gst->p.i = mlx_xpm_file_to_image(gst->gvs.m,
			gst->p.a, &gst->p.w, &gst->p.h);
}

/*This function reads the given map
 * and checks everys square, then it puts
 * its corresponding object, given in the
 * subject*/
int	ft_check_square(t_gst *gst, int x, int y)
{
	mlx_put_image_to_window(gst->gvs.m, gst->gvs.w,
		gst->bg.i, x * 50, y * 50);
	if (gst->map.buff[y][x] == 'E')
		mlx_put_image_to_window(gst->gvs.m, gst->gvs.w,
			gst->e.i, x * 50, y * 50);
	if (gst->map.buff[y][x] == '1')
		mlx_put_image_to_window(gst->gvs.m, gst->gvs.w,
			gst->w.i, x * 50, y * 50);
	if (gst->map.buff[y][x] == 'C')
		mlx_put_image_to_window(gst->gvs.m, gst->gvs.w,
			gst->cl.i, x * 50, y * 50);
	if (gst->map.buff[y][x] == 'P')
	{
		mlx_put_image_to_window(gst->gvs.m, gst->gvs.w,
			gst->p.i, x * 50, y * 50);
		gst->p.x = x;
		gst->p.y = y;
	}
	return (0);
}

/* This function checks wheter 
 * you have used a map with more than one
 * player position or that your map have at
 * least one collectable*/
int	ft_map_check_errors(t_gst *gst)
{
	if (gst->map.p > 1 || gst->map.p < 1)
	{
		printf("Error\nThis map contains more than 1 starting point");
		exit (0);
	}
	if (gst->map.c <= 0)
	{
		printf("Error\nThis map contains less than 1 collectable");
		exit (0);
	}
	return (1);
}
