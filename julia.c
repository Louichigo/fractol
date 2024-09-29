/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:20:59 by lobertho          #+#    #+#             */
/*   Updated: 2023/02/21 19:30:06 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initstructjulia(t_data *img)
{
	img->c = 0;
	img->xmin = -1.6;
	img->ymin = -1.2;
	img->zoom = 250;
	img->imax = 80;
	img->color = 0x000500;
}

void	ft_julia(t_data *img)
{
	img->i = 0;
	img->cr = img->tempcr;
	img->ci = img->tempci;
	img->zr = (img->x / img->zoom + img->xmin);
	img->zi = (img->y / img->zoom + img->ymin);
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

void	juliaco(t_data *img)
{
	img->x = 0;
	img->y = 0;
	while (img->x < LARGEUR)
	{
		while (img->y < HAUTEUR)
		{
			ft_julia(img);
			img->y++;
		}
		img->y = 0;
		img->x++;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}
