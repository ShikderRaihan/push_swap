/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshikder <rshikder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:49:48 by rshikder          #+#    #+#             */
/*   Updated: 2025/12/28 19:22:43 by rshikder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stderr_printf.h"

int	ft_hexa(unsigned int n, int ca_se)
{
	char	*base;
	int		count;

	count = 0;
	if (ca_se)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		count += ft_hexa(n / 16, ca_se);
	count += ft_putchar(base[n % 16]);
	return (count);
}

// int main()
// {
// 	unsigned int i= 16;
// 	int count;
// 	count = ft_hexa(i, 0);	
// 	printf("\n%x", i);
// }
