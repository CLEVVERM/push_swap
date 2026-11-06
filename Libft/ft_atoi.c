/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/29 17:53:26 by msotnych      #+#    #+#                 */
/*   Updated: 2026/09/29 19:24:40 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	c;
	int	s;
	int	r;

	c = 0;
	s = 1;
	r = 0;
	while (nptr[c] == ' ' || (nptr[c] >= 9 && nptr[c] <= 13))
	{
		c++;
	}
	if (nptr[c] == '-' || nptr[c] == '+')
	{
		if (nptr[c] == '-')
			s = -s;
		c++;
	}
	while (nptr[c] >= '0' && nptr[c] <= '9')
	{
		r = r * 10 + nptr[c] - '0';
		c++;
	}
	return (r * s);
}

// int main(void)
// {
// 	char * c = "-77ef9y";
// 	printf ("%d\n", ft_atoi(c));
// 	printf ("%d\n", atoi(c));
// }