/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:36:53 by lobertho          #+#    #+#             */
/*   Updated: 2023/03/02 13:51:55 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	changecolors(t_data *img)
{
	const int	colors[11] = {0x1E225C, 0xF7D1C1, 0xC6E2FF, 0x008080, 0xE8F4FF,
		0x0F056B, 0x2F1B0C, 0x462E01, 0x801818, 0x0E1122, 0xFF0921};

	if (img->c == 12)
		img->c = 0;
	img->color = colors[img->c++];
}
