/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:31:45 by lobertho          #+#    #+#             */
/*   Updated: 2023/03/02 13:52:34 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_keys(int key, t_data *img)
{
	if (key == ESC)
		exit(1);
	if (key == C)
		changecolors(img);
	if (key == R)
	{
		initfractal(img);
		launchfractal(img);
	}
	if (key == UP)
		img->ymin = img->ymin - 10 / img->zoom;
	if (key == DOWN)
		img->ymin = img->ymin + 10 / img->zoom;
	if (key == LEFT)
		img->xmin = img->xmin - 10 / img->zoom;
	if (key == RIGHT)
		img->xmin = img->xmin + 10 / img->zoom;
	launchfractal(img);
	return (0);
}

int	ft_hook(int hook, int x, int y, t_data *img)
{
	if (hook == 4)
	{
		zoom(x, y, img);
		img->zoom *= 1.2;
	}
	if (hook == 5)
	{
		dezoom(x, y, img);
		img->zoom *= 0.8;
	}
	if (hook == 1)
		img->imax += 5;
	if (hook == 2)
		img->imax -= 5;
	launchfractal(img);
	return (0);
}

void	zoom(int x, int y, t_data *img)
{
	img->xmin = ((double)x / img->zoom + img->xmin)
		- ((double)x / (img->zoom * 1.2));
	img->ymin = ((double)y / img->zoom + img->ymin)
		- ((double)y / (img->zoom * 1.2));
}

void	dezoom(int x, int y, t_data *img)
{
	img->xmin = ((double)x / img->zoom + img->xmin)
		- ((double)x / (img->zoom * 0.8));
	img->ymin = ((double)y / img->zoom + img->ymin)
		- ((double)y / (img->zoom * 0.8));
}
