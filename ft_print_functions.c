/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommorali <ommorali@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 08:50:50 by ommorali          #+#    #+#             */
/*   Updated: 2026/10/21 09:17:55 by ommorali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(long n, int base, int uppercase)
{
	int		count;
	char	*symbols;

	if (uppercase)
		symbols = "0123456789ABCDEF";
	else
		symbols = "0123456789abcdef";
	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	if (n >= base)
		count += ft_putnbr(n / base, base, uppercase);
	count += ft_putchar(symbols[n % base]);
	return (count);
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	count;

	if (!ptr)
		return (ft_putstr("(nil)"));
	count = 0;
	count += ft_putstr("0x");
	count += ft_putnbr(ptr, 16, 0);
	return (count);
}
