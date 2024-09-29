/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:40:24 by lobertho          #+#    #+#             */
/*   Updated: 2023/02/21 15:10:14 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initstructburning(t_data *img)
{
	img->c = 0;
	img->xmin = -2.1;
	img->ymin = -1.9;
	img->zoom = 220;
	img->imax = 20;
	img->color = 0x050000;
}

void	ft_burningship(t_data *img)
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
		img->zi = fabs(2 * img->zi * img->temp) + img->ci;
		img->i++;
	}
	if (img->i == img->imax)
		my_mlx_pixel_put(img, img->x, img->y, img->color);
	else
		my_mlx_pixel_put(img, img->x, img->y, (img->color * img->i));
}

void	burningco(t_data *img)
{
	img->x = 0;
	img->y = 0;
	while (img->x < LARGEUR)
	{
		while (img->y < HAUTEUR)
		{
			ft_burningship(img);
			img->y++;
		}
		img->y = 0;
		img->x++;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}
