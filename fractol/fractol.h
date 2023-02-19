/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:02:49 by lobertho          #+#    #+#             */
/*   Updated: 2023/02/19 16:48:47 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include "./mlx/mlx.h"

# define ESC	53

# define	LARGEUR	800
# define	HAUTEUR	600

# define XMIN -2.1
# define XMAX 0.6
# define YMIN -1.2
# define YMAX 1.2
# define ZOOM 220
# define IMAX 50

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int	ft_keys(int key, void *param);
int	ft_hook(int hook, void *param);
int	ft_colors(int color);
void	mandelco(t_data img);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif