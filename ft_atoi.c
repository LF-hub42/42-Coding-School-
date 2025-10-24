/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:07:11 by ekypraio          #+#    #+#             */
/*   Updated: 2025/10/24 15:40:58 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Prüft, ob ein Zeichen ein Leerraumzeichen ist (z. B. Leerzeichen, Tab, Zeilenumbruch)

int	ft_isspace(int character)
{
	if (character == 32 || (character >= 9 && character <= 13))
		return (1);
	return (0);
}

// Wandelt eine Zeichenkette (String) in eine Ganzzahl (int) um
\
int	ft_atoi(const char *char_pointer)
{
	int	sign;
	int	result;
// Speichert das Vorzeichen (+1 oder -1)
// Speichert die berechnete Zahl

	sign = 1;
	result = 0;

	// Der Pointer wird einmal dekrementiert(-1), weil im nächsten Schritt (++char_pointer)
	// direkt inkrementiert (+1) wird,um die erste Prüfung zu erleichtern.

	--char_pointer;

	// Überspringt alle Leerzeichen und andere Whitespace Zeichen

	while (ft_isspace(*++char_pointer));

	// Prüft, ob ein Vorzeichen (+ oder -) vorhanden ist

	if (*char_pointer == '+' || *char_pointer == '-')
	{
		// Wenn das Vorzeichen '-', dann Zahl negativ machen

		if (*char_pointer == '-')
			sign *= -1;
		char_pointer++;
	}
	while (ft_isdigit(*char_pointer))
	{
		result = result * 10 + (*char_pointer - '0');
		char_pointer++;
	}
	return (result * sign);
}
