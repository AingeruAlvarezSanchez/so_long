/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fts1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarez <aalvarez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 17:04:14 by aalvarez          #+#    #+#             */
/*   Updated: 2021/08/16 15:34:51 by aalvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx_opengl_20191021/mlx.h"

/*This is a function that gives us a count of
 * each non wall or bg object, used for error solving
 * purposes or for counting left collectables*/
void	ft_map_check(t_gst *gst)
{
	int	x;
	int	y;

	y = 0;
	gst->map.c = 0;
	gst->map.e = 0;
	gst->map.p = 0;
	while (y < gst->map.y)
	{
		x = 0;
		while (x < gst->map.x)
		{
			if (gst->map.buff[y][x] == 'C')
				gst->map.c += 1;
			if (gst->map.buff[y][x] == 'E')
				gst->map.e += 1;
			if (gst->map.buff[y][x] == 'P')
				gst->map.p += 1;
			x++;
		}
		y++;
	}
	ft_map_check_errors(gst);
}

/*This function creates the given map inside the
 * double array variable that we have already mallocadted*/
void	ft_map_gen(t_gst *gst, char **argv)
{
	int	i;
	int	x;
	int	fd;

	i = 0;
	x = 0;
	fd = open(argv[1], O_RDONLY);
	while (x < gst->map.x)
	{
		read(fd, &gst->map.buff[i][x], 1);
		if (gst->map.buff[i][x] == '\n')
		{
			if (x != gst->map.x - 1)
				ft_error_rectangle();
			gst->map.buff[i][x] = '\0';
			i++;
			x = 0;
			continue ;
		}
		x++;
	}
	x--;
	gst->map.buff[i][x] = '\0';
	close (fd);
	invalid_walls_error(gst);
}

/*This function is responsible for mallocating 
 * the memory of the map that is being created*/
int	ft_map_malloc(t_gst *gst)
{
	int		i;

	gst->map.buff = (char **)malloc((gst->map.y + 1) * sizeof(char *));
	if (!gst->map.buff)
		return (0);
	i = 0;
	while (i < gst->map.y)
	{
		gst->map.buff[i] = malloc(gst->map.x);
		if (!gst->map.buff)
		{
			i = 0;
			while (i < gst->map.y)
			{
				free(gst->map.buff[i]);
				i++;
			}
			free(gst->map.buff);
			return (0);
		}
		i++;
	}
	return (1);
}

/*A simple function to initialize variables*/
void	initialize_pos(t_gst *gst)
{
	//gst->p.moves = 0;
	gst->map.x = 0;
	gst->map.y = 0;
}

/*This function reads the map*/
int	ft_map_count(char **argv, t_gst *gst)
{
	int		fd;
	char	buffer;

	initialize_pos(gst);
	fd = open(argv[1], O_RDONLY);
	if (fd < 2 || fd > 3)
	{
		printf("Error\nInvalid map, please try again");
		return (0);
	}
	while (read(fd, &buffer, 1))
	{
		gst->map.x++;
		if (buffer == '\n')
			break ;
	}
	while (read(fd, &buffer, 1))
	{
		if (buffer == '\n')
			gst->map.y++;
	}
	close(fd);
	gst->map.y += 2;
	return (1);
}
