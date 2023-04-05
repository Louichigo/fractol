/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 23:28:10 by lobertho          #+#    #+#             */
/*   Updated: 2023/03/02 13:55:35 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dest;

	dest = data->addr + (y * data->line_length + x
			* (data->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}

int	ft_exit(void)
{
	exit(1);
}

void	ft_erreur(void)
{
	ft_printf("saisissez des parametres valides:\n./fractol mandelbrot\n");
	ft_printf("./fractol burningship\n./fractol julia (x ,iy)\n");
	exit(1);
}

void	arguments(t_data *img, char **argv)
{
	img->check = ft_checkfractal(img);
	if (img->argtemp == 4)
	{
		img->tempcr = ft_atof(argv[2]);
		img->tempci = ft_atof(argv[3]);
	}
}
