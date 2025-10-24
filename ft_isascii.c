/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:58:03 by ekypraio          #+#    #+#             */
/*   Updated: 2025/10/24 15:42:11 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Prüft, ob ein Zeichen ein ASCII-Zeichen ist(0-127)

int	ft_isascii(int character)
{

	if (character >= 0 && character <= 127)
		return (1);
	return (0);
}

