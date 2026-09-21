/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 20:50:06 by ekypraio          #+#    #+#             */
/*   Updated: 2025/11/10 18:13:11 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_format(va_list args, char format);
int		ft_print_char(int c);
int		ft_print_str(char *s);
int		ft_print_nbr(int n);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putptr(void *ptr);
int		ft_putnbr_fd(int n, int fd);
int		ft_putnbr_x(unsigned long long nbr, char c);
size_t	ft_strlen(const char *s);

#endif
