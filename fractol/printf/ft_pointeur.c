/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointeur.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:34:09 by lobertho          #+#    #+#             */
/*   Updated: 2022/11/18 11:10:22 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointeur(void *ptr, int *count)
{
	ft_string("0x", count);
	ft_hexamin((unsigned long)ptr, count);
	return (*count);
}
