/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:02:49 by lobertho          #+#    #+#             */
/*   Updated: 2023/03/02 13:55:48 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "./mlx/mlx.h"
# include "./printf/ft_printf.h"

# define ESC	53
# define C	8
# define R	15
# define UP	126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

enum {
	ON_DESTROY = 17
};

# define LARGEUR	800
# define HAUTEUR	600

typedef struct s_data {
	void	*mlx;
	void	*mlx_win;
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		argtemp;
	double	tempcr;
	double	tempci;
	int		c;
	int		x;
	int		y;
	double	xmin;
	double	ymin;
	int		i;
	int		color;
	int		imax;
	int		mouse;
	int		check;
	double	zoom;
	double	zr;
	double	zi;
	double	cr;
	double	ci;
	double	temp;
	char	*argvtemp;
}				t_data;

int		ft_keys(int key, t_data *img);
int		ft_hook(int hook, int x, int y, t_data *img);
int		ft_strcmp(char *s1, char *s2);
int		ft_checkfractal(t_data *img);
int		ft_exit(void);

double	ft_atof(const char *str);

void	mandelco(t_data *img);
void	initstructmandel(t_data *img);
void	juliaco(t_data *img);
void	initstructjulia(t_data *img);
void	burningco(t_data *img);
void	initstructburning(t_data *img);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	changecolors(t_data *img);
void	zoom(int x, int y, t_data *img);
void	dezoom(int x, int y, t_data *img);
void	initfractal(t_data *img);
void	launchfractal(t_data *img);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_erreur(void);
void	arguments(t_data *img, char **argv);

#endif