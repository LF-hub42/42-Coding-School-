/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 17:07:50 by ekypraio          #+#    #+#             */
/*   Updated: 2025/08/20 14:47:00 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 'A' && str[i] <= 'Z'))
			return (0);
		i++;
	}
	return (1);
}

// #include <stdio.h>

// int main (void)
// {
//     printf("%d\n", ft_str_is_uppercase(""));
//     printf("%d\n", ft_str_is_uppercase("abcd"));
//     printf("%d\n", ft_str_is_uppercase("1234"));
// }