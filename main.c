/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:13:54 by lobertho          #+#    #+#             */
/*   Updated: 2023/02/22 00:58:57 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_checkfractal(t_data *img)
{
	if ((ft_strcmp(img->argvtemp, "mandelbrot")) == 0)
		img->check = 1;
	else if (ft_strcmp(img->argvtemp, "julia") == 0)
		img->check = 2;
	else if (ft_strcmp(img->argvtemp, "burningship") == 0)
		img->check = 3;
	else
	{
		ft_printf("saisissez des parametres valides:\n./fractol mandelbrot\n");
		ft_printf("./fractol burningship\n./fractol julia (x ,iy)\n");
		exit (1);
	}
	return (img->check);
}

void	initfractal(t_data *img)
{
	if (img->check == 1)
		initstructmandel(img);
	else if (img->check == 2)
	{
		initstructjulia(img);
		if (img->argtemp == 2)
		{
			img->tempcr = 0.285;
			img->tempci = 0.01;
		}
	}
	else if (img->check == 3)
		initstructburning(img);
}

void	launchfractal(t_data *img)
{
	if (img->check == 1)
		mandelco(img);
	else if (img->check == 2)
		juliaco(img);
	else if (img->check == 3)
		burningco(img);
}

int	main(int argc, char **argv)
{
	t_data	*img;

	img = (t_data *)malloc(sizeof(t_data));
	if (!img)
		return (-1);
	img->argtemp = argc;
	img->argvtemp = argv[1];
	if (img->argtemp == 2 || img->argtemp == 4)
		arguments(img, argv);
	else
		ft_erreur();
	img->mlx = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx, LARGEUR, HAUTEUR, "fractol");
	img->img = mlx_new_image(img->mlx, LARGEUR, HAUTEUR);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	initfractal(img);
	launchfractal(img);
	mlx_key_hook(img->mlx_win, ft_keys, img);
	mlx_mouse_hook(img->mlx_win, ft_hook, img);
	mlx_hook(img->mlx_win, ON_DESTROY, 0, ft_exit, img);
	mlx_loop(img->mlx);
}
