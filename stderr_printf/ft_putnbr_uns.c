/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshikder <rshikder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 00:57:29 by rshikder          #+#    #+#             */
/*   Updated: 2025/12/28 19:35:42 by rshikder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stderr_printf.h"

int	ft_putnbr_uns(unsigned int n)
{
	int	x;

	x = 0;
	if (n > 9)
		x += ft_putnbr_uns(n / 10);
	n = (n % 10) + '0';
	x += ft_putchar(n);
	return (x);
}

// int main()
// {
// 	unsigned int x = -6544464;
// 	int i;
// 	i = ft_uns_digit(x);
// 	printf("\n%u", x);
// 	printf("\n%d", i);
// }