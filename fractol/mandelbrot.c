/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:53:01 by lobertho          #+#    #+#             */
/*   Updated: 2023/02/21 14:34:37 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initstructmandel(t_data *img)
{
	img->c = 0;
	img->xmin = -2.1;
	img->ymin = -1.3;
	img->zoom = 220;
	img->imax = 50;
	img->color = 0x000005;
}

void	ft_mandelbrot(t_data *img)
{
	img->i = 0;
	img->zr = 0;
	img->zi = 0;
	img->cr = (img->x / img->zoom + img->xmin);
	img->ci = (img->y / img->zoom + img->ymin);
	while ((img->zr * img->zr) + (img->zi * img->zi) < 4 && img->i < img->imax)
	{
		img->temp = img->zr;
		img->zr = (img->temp * img->temp) - (img->zi * img->zi) + img->cr;
		img->zi = (2 * img->zi * img->temp) + img->ci;
		img->i++;
	}
	if (img->i == img->imax)
		my_mlx_pixel_put(img, img->x, img->y, img->color);
	else
		my_mlx_pixel_put(img, img->x, img->y, (img->color * img->i));
}

void	mandelco(t_data *img)
{
	img->x = 0;
	img->y = 0;
	while (img->x < LARGEUR)
	{
		while (img->y < HAUTEUR)
		{
			ft_mandelbrot(img);
			img->y++;
		}
		img->y = 0;
		img->x++;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}
