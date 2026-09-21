/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 23:06:26 by ekypraio          #+#    #+#             */
/*   Updated: 2025/11/09 22:03:54 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	count;

	if (s == NULL)
		return (-1);
	count = 0;
	while (*s)
	{
		if (write(fd, s, 1) == -1)
			return (-1);
		s++;
		count++;
	}
	return (count);
}
// schreibt einen String s Zeichen für Zeichen auf einen
// bestimmten File Descriptor fd z. B. 1 für Standardausgabe
