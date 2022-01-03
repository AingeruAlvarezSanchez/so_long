/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarez <aalvarez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 13:40:06 by aalvarez          #+#    #+#             */
/*   Updated: 2021/08/12 19:59:38 by aalvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx_opengl_20191021/mlx.h"

/*This function will redraw our player image
 * each time we press one of the movements keys*/
int	ft_movement(int keycode, t_gst *gst)
{
	if (keycode == 13)
		ft_kc13(gst);
	if (keycode == 0)
		ft_kc0(gst);
	if (keycode == 1)
		ft_kc1(gst);
	if (keycode == 2)
		ft_kc2(gst);
	return (0);
}

/*This function creates the first image you will
 * see once the game opens, that image will be later
 * redrawn*/
int	ft_first_image(t_gst *gst)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	gst->map.x = (gst->map.x / 50);
	gst->map.y = (gst->map.y / 50);
	fill_images(gst);
	while (y < gst->map.y)
	{
		x = 0;
		while (x < gst->map.x)
		{
			ft_check_square(gst, x, y);
			x++;
		}
		y++;
	}
	return (1);
}

/*This is a father function for all the 
 * functions that will make the game work
 * after the initial error checks*/
int	ft_start_game(t_gst	*gst)
{
	gst->map.x = (gst->map.x - 1) * 50;
	gst->map.y = (gst->map.y) * 50;
	gst->gvs.w = mlx_new_window(gst->gvs.m, gst->map.x, gst->map.y, "So_long");
	ft_first_image(gst);
	mlx_hook(gst->gvs.w, 3, 1L << 1, ft_movement, gst);
	mlx_hook(gst->gvs.w, 17, 1L << 17, ft_close_x, &gst);
	mlx_hook(gst->gvs.w, 2, 1L << 0, ft_close_esc, &gst);
	mlx_loop(gst->gvs.m);
	return (1);
}

int	main(int argc, char **argv)
{
	t_gst	gst;

	gst.gvs.m = mlx_init();
	if (argc < 2 || argc > 2)
	{
		printf("Error\nInvalid number of arguments, try again");
		return (0);
	}
	else if (argc == 2)
	{
		if (ft_map_count(argv, &gst) == 0)
			return (0);
		else
		{
			ft_map_malloc(&gst);
			ft_map_gen(&gst, argv);
			ft_map_check(&gst);
			ft_start_game(&gst);
		}
	}
	return (0);
}
