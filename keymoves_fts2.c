/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymoves_fts2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarez <aalvarez@student.42urduliz>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 18:36:00 by aalvarez          #+#    #+#             */
/*   Updated: 2021/08/12 20:01:07 by aalvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx_opengl_20191021/mlx.h"

int	check_next_kc0(t_gst *gst)
{
	if (gst->map.buff[gst->p.y][gst->p.x - 1] == '1')
		return (0);
	if (gst->map.buff[gst->p.y][gst->p.x - 1] == 'C')
	{
		gst->map.c -= 1;
		printf("Remainig collectables: [%d]\n", gst->map.c);
		gst->map.buff[gst->p.y][gst->p.x - 1] = '0';
		return (1);
	}
	else if (gst->map.buff[gst->p.y][gst->p.x - 1] == 'E' && gst->map.c == 0)
	{
		printf("Congratulations! You escaped the castle!");
		mlx_clear_window(gst->gvs.m, gst->gvs.w);
		exit (0);
	}
	return (1);
}

int	check_next_kc13(t_gst *gst)
{
	if (gst->map.buff[gst->p.y - 1][gst->p.x] == '1')
		return (0);
	if (gst->map.buff[gst->p.y - 1][gst->p.x] == 'C')
	{
		gst->map.c -= 1;
		printf("Remainig collectables: [%d]\n", gst->map.c);
		gst->map.buff[gst->p.y - 1][gst->p.x] = '0';
		return (1);
	}
	else if (gst->map.buff[gst->p.y - 1][gst->p.x] == 'E' && gst->map.c == 0)
	{
		printf("Congratulations! You escaped the castle!");
		mlx_clear_window(gst->gvs.m, gst->gvs.w);
		exit (0);
	}
	return (1);
}

int	check_next_kc1(t_gst *gst)
{
	if (gst->map.buff[gst->p.y + 1][gst->p.x] == '1')
		return (0);
	if (gst->map.buff[gst->p.y + 1][gst->p.x] == 'C')
	{
		gst->map.c -= 1;
		printf("Remainig collectables: [%d]\n", gst->map.c);
		gst->map.buff[gst->p.y + 1][gst->p.x] = '0';
		return (1);
	}
	else if (gst->map.buff[gst->p.y + 1][gst->p.x] == 'E' && gst->map.c == 0)
	{
		printf("Congratulations! You escaped the castle!");
		mlx_clear_window(gst->gvs.m, gst->gvs.w);
		exit (0);
	}
	return (1);
}

int	check_next_kc2(t_gst *gst)
{
	if (gst->map.buff[gst->p.y][gst->p.x + 1] == '1')
		return (0);
	if (gst->map.buff[gst->p.y][gst->p.x + 1] == 'C')
	{
		gst->map.c -= 1;
		printf("Remainig collectables: [%d]\n", gst->map.c);
		gst->map.buff[gst->p.y][gst->p.x + 1] = '0';
		return (1);
	}
	else if (gst->map.buff[gst->p.y][gst->p.x + 1] == 'E' && gst->map.c == 0)
	{
		printf("Congratulations! You escaped the castle!");
		mlx_clear_window(gst->gvs.m, gst->gvs.w);
		exit (0);
	}
	return (1);
}
