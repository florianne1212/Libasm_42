/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 22:05:16 by user42            #+#    #+#             */
/*   Updated: 2020/06/18 15:09:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libasm.h"

void	test_int(int a, int b)
{
	if (a == b)
		printf("\nSame result real %i mine %i", a, b);
	else
		printf("\nNot the same real %i mine %i", a, b);
}

void	cmp_char(char *s1, char *s2)
{
	if (strcmp(s1, s2) != 0)
		printf("\nNot the same result real %s\nmine %s", s1, s2);
	else
		printf("\nSame result\nreal : %s\nmine : %s", s1, s2);
}

void	test_sign(int a, int b)
{
	if ((a > 0 && b > 0) || (a < 0 && b < 0) || (a == 0 && b == 0))
		printf("\nSame sign real %i mine %i", a, b);
	else
		printf("\nNot the same sign real %i mine %i", a, b);
}

void	clear_s1(char *s1)
{
	int i;

	i = 0;
	while (s1[i] != '\0')
	{
		s1[i] = 0;
		i++;
	}
}

void	cmp_char_free(char *s1, char *s2)
{
	if (strcmp(s1, s2) != 0)
		printf("\nNot the same result real %s\nmine %s", s1, s2);
	else
		printf("\nSame result\nreal : %s\nmine : %s", s1, s2);
	free(s1);
	free(s2);
}
