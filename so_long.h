/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarez <aalvarez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 13:41:43 by aalvarez          #+#    #+#             */
/*   Updated: 2021/08/16 11:46:20 by aalvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
//Struct for exit
typedef struct s_e
{
	void	*i;
	char	*a;
	int		w;
	int		h;
}	t_e;
//Struct for player
typedef struct s_p
{
	void	*i;
	char	*a;
	int		w;
	int		h;
	int		x;
	int		y;
}	t_p;
//Struct for collectables
typedef struct s_cl
{
	void	*i;
	char	*a;
	int		w;
	int		h;
}	t_cl;
//Struct for background
typedef struct s_bg
{
	void	*i;
	char	*a;
	int		w;
	int		h;
}	t_bg;
//Struct for walls
typedef struct s_w
{
	void	*i;
	char	*a;
	int		w;
	int		h;
}	t_w;
//Struct for global variables
typedef struct s_gvs
{
	void	*m;
	void	*w;
}	t_gvs;
//Struct for map creation related variables
typedef struct s_map
{
	int		x;
	int		y;
	int		c;
	int		p;
	int		e;
	char	**buff;
}	t_map;
//General Struct that englobes the rest of structs
typedef struct s_gst
{
	t_gvs	gvs;
	t_map	map;
	t_w		w;
	t_bg	bg;
	t_p		p;
	t_e		e;
	t_cl	cl;
}	t_gst;

void	initialize_pos(t_gst *gst);
int		ft_map_count(char **argv, t_gst *gst);
int		ft_map_malloc(t_gst *gst);
void	ft_map_gen(t_gst *gst, char **argv);
void	ft_map_check(t_gst *gst);
int		ft_map_check_errors(t_gst *gst);
int		ft_close_x(void);
int		ft_close_esc(int keycode);
void	fill_images(t_gst *gst);
int		ft_check_square(t_gst *gst, int x, int y);
int		ft_movement(int keycode, t_gst *gst);
void	ft_redraw(t_gst *gst, int x, int y);
int		redraw_start(t_gst *gst);
void	ft_kc13(t_gst *gst);
void	ft_kc0(t_gst *gst);
void	ft_kc1(t_gst *gst);
void	ft_kc2(t_gst *gst);
int		check_next_kc13(t_gst *gst);
int		check_next_kc0(t_gst *gst);
int		check_next_kc1(t_gst *gst);
int		check_next_kc2(t_gst *gst);
void	collectable_clear(t_gst *gst);
void	invalid_walls_error(t_gst *gst);
void	ft_error_rectangle(void);
void	ft_closemap_error(void);

#endif
