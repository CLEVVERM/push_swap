/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/09 15:26:16 by msotnych      #+#    #+#                 */
/*   Updated: 2026/10/09 17:36:47 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	counter(long n)
{
	unsigned int	c;

	c = 0;
	if (n <= 0)
	{
		c++;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		c++;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	int		l;
	long	nb;
	char	*s;

	nb = n;
	l = counter(nb);
	s = malloc(l + 1 * sizeof(char ));
	if (!s)
		return (NULL);
	s[l] = '\0';
	if (n < 0)
	{
		s[0] = '-';
		nb = -nb;
	}
	if (n == 0)
		s[0] = '0';
	while (nb > 0)
	{
		l--;
		s[l] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (s);
}

// int main(void)
// {
// 	int n = 244;
// 	printf("%s\n", ft_itoa(n));
// }