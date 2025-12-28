/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stderr_printf.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshikder <rshikder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 20:02:15 by rshikder          #+#    #+#             */
/*   Updated: 2025/12/28 19:39:49 by rshikder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STDERR_PRINTF_H
# define STDERR_PRINTF_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdint.h>
# include <stdarg.h>

int	stderr_ft_check(char prin, va_list cpy);
int	ft_putnbr(int n);
int	ft_hexa(unsigned int n, int ca_se);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_ptr(void *ptr);
int	ft_putnbr_uns(unsigned int n);
int	stderr_printf(const char *prin, ...);

#endif
