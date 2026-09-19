/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourlogin <you@student.42.fr>               +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:00:00 by yourlogin         #+#    #+#             */
/*   Updated: 2025/10/27 15:00:00 by yourlogin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_len(long n)
{
	int	len;

	len = 1;
	if (n < 0)
		n = -n;
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*res;
	long	nb;
	int		len;
	int		sign;

	nb = n;
	sign = (nb < 0);
	len = digit_len(nb) + sign;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (nb < 0)
		nb = -nb;
	while (len-- > 0)
	{
		res[len] = (nb % 10) + '0';
		nb /= 10;
		if (nb == 0 && sign && len == 1)
			break ;
	}
	if (sign)
		res[0] = '-';
	return (res);
}

// ft_itoa:
// Wandelt eine ganze Zahl 'n' in einen String um.
// Gibt den String zurück, der die Zahl darstellt,
// oder NULL, wenn malloc fehlschlägt.
// Negative Zahlen werden mit '-' ausgegeben.
