/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:31:45 by lobertho          #+#    #+#             */
/*   Updated: 2023/02/19 16:16:30 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_keys(int key, void *param)
{
	if (key == ESC)
		exit(1);
	return (0);
}

int	ft_hook(int hook, void *param)
{
	return (0);
}