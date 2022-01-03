/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymoves_fts1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarez <aalvarez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 16:49:18 by aalvarez          #+#    #+#             */
/*   Updated: 2021/08/12 19:28:14 by aalvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx_opengl_20191021/mlx.h"

void	ft_kc0(t_gst *gst)
{
	if (check_next_kc0(gst) == 1)
	{
		mlx_clear_window(gst->gvs.m, gst->gvs.w);
		redraw_start(gst);
		mlx_put_image_to_window(gst->gvs.m, gst->gvs.w, gst->p.i,
			(gst->p.x - 1) * 50, gst->p.y * 50);
		gst->p.x -= 1;
	}
}

void	ft_kc13(t_gst *gst)
{
	if (check_next_kc13(gst) == 1)
	{
		mlx_clear_window(gst->gvs.m, gst->gvs.w);
		redraw_start(gst);
		mlx_put_image_to_window(gst->gvs.m, gst->gvs.w, gst->p.i,
			gst->p.x * 50, (gst->p.y - 1) * 50);
		gst->p.y -= 1;
	}
}

void	ft_kc1(t_gst *gst)
{
	if (check_next_kc1(gst) == 1)
	{
		mlx_clear_window(gst->gvs.m, gst->gvs.w);
		redraw_start(gst);
		mlx_put_image_to_window(gst->gvs.m, gst->gvs.w, gst->p.i,
			gst->p.x * 50, (gst->p.y + 1) * 50);
		gst->p.y += 1;
	}
}

void	ft_kc2(t_gst *gst)
{
	if (check_next_kc2(gst) == 1)
	{
		mlx_clear_window(gst->gvs.m, gst->gvs.w);
		redraw_start(gst);
		mlx_put_image_to_window(gst->gvs.m, gst->gvs.w, gst->p.i,
			(gst->p.x + 1) * 50, gst->p.y * 50);
		gst->p.x += 1;
	}
}
