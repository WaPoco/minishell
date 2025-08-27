/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmote <hmote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:07:31 by hmote             #+#    #+#             */
/*   Updated: 2025/04/08 22:28:53 by hmote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	handle_specifier(char specifier, va_list args)
{
	size_t			len;

	if (specifier == 'c')
		len = print_chr(va_arg(args, int));
	else if (specifier == 's')
		len = print_str(va_arg(args, char *));
	else if (specifier == 'p')
		len = print_ptr(va_arg(args, void *));
	else if (specifier == 'd' || specifier == 'i')
		len = print_num(va_arg(args, int));
	else if (specifier == 'u')
		len = print_un_num(va_arg(args, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		len = print_hex(va_arg(args, unsigned int), specifier == 'X');
	else if (specifier == '%')
		len = print_chr('%');
	else
	{
		ft_putchar_fd('%', 1);
		ft_putchar_fd(specifier, 1);
		len = 2;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	size_t		total_chars;

	va_start(args, format);
	total_chars = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			total_chars += handle_specifier(*format, args);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			total_chars++;
		}
		format++;
	}
	va_end(args);
	return (total_chars);
}
