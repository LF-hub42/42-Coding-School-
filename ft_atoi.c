/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:07:11 by ekypraio          #+#    #+#             */
/*   Updated: 2025/10/24 19:10:38 by ekypraio         ###   ########.fr       */
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
// int	ft_isspace(int character)
// {
// 	if (character == 32 || (character >= 9 && character <= 13))
// 		return (1);
// 	return (0);
// }

// // Wandelt eine Zeichenkette (String) in eine Ganzzahl (int) um
// int	ft_atoi(const char *char_pointer)
// {
// 	int	sign;
// 	int	result;

// 	sign = 1;
// 	result = 0;
// // Vorzeichen: +1 oder -1
// // Speichert die berechnete Zahl

// 	--char_pointer;

// // Pointer wird einmal dekrementiert, weil ++char_pointer folgt
// 	// Überspringt alle Leerzeichen

// 	while (ft_isspace(*++char_pointer))
// 		;

// 	// Prüft, ob ein Vorzeichen vorhanden ist
// 	if (*char_pointer == '+' || *char_pointer == '-')
// 	{
// 		if (*char_pointer == '-')
