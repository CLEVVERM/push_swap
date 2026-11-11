/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/03 14:36:15 by msotnych      #+#    #+#                 */
/*   Updated: 2026/11/11 18:28:29 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int str_to_num(int *num, char *str)
{
	int s;
	long res;
	int c;
	
	s = 1;
	res = 0;
	c = 0;
	while (str[c] == ' ' || (str[c] >= 9 && str[c] <= 13))
	{
		c++;
	}
	if  (str[c] == '-' || str[c] == '+')
	{
		if (str[c] == '-')
			s = -s;
		c++;
	}
	if (str[c] == '\0')
		return (0);
	if (str[c] >= '9' || str[c] <= '0')
		return (0);
	while (str[c] != '\0')
	{
		if (res * s > INT_MAX || res * s < INT_MIN)
			return (0);
		res = res * 10 + str[c] - '0';
		c++;
	}
	*num = res;
	return (1);
}

int main(void)
{
	int *c;
	c = NULL;
	char *str;
	str = "452 455 -56 +56";
	printf("%d", str_to_num(c, str));
}
