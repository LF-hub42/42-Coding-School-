/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:07:11 by ekypraio          #+#    #+#             */
/*   Updated: 2025/10/27 01:00:58 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *n)
{
	int	num;
	int	is_neg;

	is_neg = 0;
	num = 0;
	while ((*n >= 9 && *n <= 13) || *n == 32)
		n++;
	if (*n == '-' || *n == '+')
	{
		if (*n == '-')
			is_neg = 1;
		n++;
	}
	while (*n >= '0' && *n <= '9')
	{
		num *= 10;
		num += (*n - 48);
		n++;
	}
	if (is_neg == 1)
		num *= -1;
	return (num);
}
// 		// Prüft, ob ein Zeichen ein Leerraumzeichen ist
// // (z. B. Leerzeichen, Tab, Zeilenumbruch)
