/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 00:54:46 by ekypraio          #+#    #+#             */
/*   Updated: 2025/08/16 14:16:36 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	duda;

	duda = 0;
	while (str[duda] != '\0')
	{
		write(1, &str[duda], 1);
		duda++;
	}
}

// int main()
// {
// 	ft_putstr("Hello");
// }
