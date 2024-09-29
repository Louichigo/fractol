/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:43:17 by lobertho          #+#    #+#             */
/*   Updated: 2022/11/18 11:08:33 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_pointeur(void *ptr, int *count);
int	ft_printf(const char *strf, ...);
int	ft_putchar(int c, int *count);
int	ft_hexamaj(unsigned long i, int *count);
int	ft_hexamin(unsigned long i, int *count);
int	ft_int(int i, int *count);
int	ft_string(const char *str, int *count);
int	ft_unsint(unsigned int i, int *count);

#endif
