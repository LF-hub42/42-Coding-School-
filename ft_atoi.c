/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:07:11 by ekypraio          #+#    #+#             */
/*   Updated: 2025/10/23 16:11:34 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Prüft, ob ein Zeichen ein Leerraumzeichen ist (z. B. Leerzeichen, Tab, Zeilenumbruch)
int	ft_isspace(int character)
{
	if (character == 32 || (character >= 9 && character <= 13))
		return (1);  // true,ein Leerraum
	return (0);      // false,kein Leerraum
}

// Wandelt eine Zeichenkette (String) in eine Ganzzahl (int) um
int	ft_atoi(const char *char_pointer)
{
	int	sign;       // Speichert das Vorzeichen (+1 oder -1)
	int	result;     // Speichert die berechnete Zahl

	sign = 1;       // Standardmäßig positiv
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
		char_pointer++; // Zum nächsten Zeichen weitergehen
	}

	// Solange das aktuelle Zeichen eine Ziffer ist
	while (ft_isdigit(*char_pointer))
	{
		// Zahl = (alte Zahl * 10) + neue Ziffer
		result = result * 10 + (*char_pointer - '0');
		char_pointer++;
	}

	// Rückgabe der fertigen Zahl (unter Berücksichtigung des Vorzeichens)
	return (result * sign);
}
