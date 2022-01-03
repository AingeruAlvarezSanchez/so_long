/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_fts1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarez <aalvarez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 19:13:55 by aalvarez          #+#    #+#             */
/*   Updated: 2021/08/12 14:58:50 by aalvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*This function receives an order whenever you press
 * the "esc" key, telling the window and program to close*/
int	ft_close_esc(int keycode)
{
	if (keycode == 53)
		exit (0);
	return (0);
}

/*This functions does the exact same thing as the above one,
 * the only difference is that this one works whenever you
 * press the red x on the window*/
int	ft_close_x(void)
{
	exit (0);
	return (0);
}
