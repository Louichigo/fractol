/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:13:54 by lobertho          #+#    #+#             */
/*   Updated: 2023/02/19 16:38:29 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dest;

	dest = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 9));
	*(unsigned int*)dest = color;
}

int main()
{
 void	*mlx;
 void	*mlx_win;
 t_data	img;

mlx = mlx_init();
mlx_win = mlx_new_window(mlx, LARGEUR, HAUTEUR, "fractol");
img.img = mlx_new_image(mlx, (XMAX - XMIN) * ZOOM, (YMAX - YMIN) * ZOOM);
img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, 
	&img.endian);
mandelco(img);
mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
mlx_key_hook(mlx_win, ft_keys, (void *)0);
mlx_mouse_hook(mlx_win, ft_hook, (void *)0);
mlx_loop(mlx);
}