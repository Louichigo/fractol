/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:54:42 by lobertho          #+#    #+#             */
/*   Updated: 2023/02/22 00:24:10 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	operations(const char *str, float result, float scale, int afterdot)
{
	while (*str)
	{
		if (afterdot == 1)
		{
			scale = scale / 10;
			result = result + (*str - '0') * scale;
		}
		else
		{
			if (*str == '.')
				afterdot++;
			else
				result = result * 10.0 + (*str - '0');
		}
		str++;
	}
	return (result);
}

double	ft_atof(const char *str)
{
	int		afterdot;
	int		sign;
	float	result;
	float	scale;

	afterdot = 0;
	scale = 1;
	sign = 0;
	result = 0;
	if (*str == '-')
	{
		str++;
		sign = 1;
	}
	result = operations(str, result, scale, afterdot);
	if (sign == 1)
		return (-result);
	else
		return (result);
}	
