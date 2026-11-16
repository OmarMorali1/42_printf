/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommorali <ommorali@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 08:50:20 by ommorali          #+#    #+#             */
/*   Updated: 2026/10/21 09:17:19 by ommorali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_format(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (c == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		count += ft_print_ptr(va_arg(args, unsigned long long));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr((long)va_arg(args, int), 10, 0);
	else if (c == 'u')
		count += ft_putnbr((unsigned long)va_arg(args, unsigned int), 10, 0);
	else if (c == 'x')
		count += ft_putnbr((unsigned long)va_arg(args, unsigned int), 16, 0);
	else if (c == 'X')
		count += ft_putnbr((unsigned long)va_arg(args, unsigned int), 16, 1);
	else if (c == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		print_len;

	if (!format)
		return (-1);
	i = 0;
	print_len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			print_len += ft_handle_format(format[i], args);
		}
		else
			print_len += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (print_len);
}
