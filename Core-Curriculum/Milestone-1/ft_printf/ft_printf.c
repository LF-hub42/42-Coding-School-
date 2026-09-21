/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:36:10 by ekypraio          #+#    #+#             */
/*   Updated: 2025/11/10 18:20:14 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**handle_format:
**Nimmt das aktuelle Formatzeichen und wählt die passende Ausgabefunktion
*/
static int	handle_format(char type, va_list args)
{
	char	*str;

	if (type == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	else if (type == 's')
	{
		str = va_arg(args, char *);
		if (!str)
			return (ft_putstr_fd("(null)", 1));
		return (ft_putstr_fd(str, 1));
	}
	else if (type == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (type == 'd' || type == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	else if (type == 'u')
		return (ft_putnbr_x(va_arg(args, unsigned int), 'u'));
	else if (type == 'x' || type == 'X')
		return (ft_putnbr_x(va_arg(args, unsigned int), type));
	else if (type == '%')
		return (ft_putchar_fd('%', 1));
	return (0);
}

/*
**ft_printf:
**Liest das Format-String, erkennt % und ruft handle_format() auf
**Gibt die Gesamtanzahl der ausgegebenen Zeichen zurück
*/
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			count += handle_format(format[i + 1], args);
			i++;
		}
		else
			count += ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
