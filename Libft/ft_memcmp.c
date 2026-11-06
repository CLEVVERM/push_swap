/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/05 18:02:39 by msotnych      #+#    #+#                 */
/*   Updated: 2026/10/06 19:14:08 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*a;
	const unsigned char	*b;

	a = (const unsigned char *)s1;
	b = (const unsigned char *)s2;
	while (n--)
	{
		if (*a != *b)
			return (*a - *b);
		a++;
		b++;
	}
	return (0);
}

// int main(void)
// {
// 	unsigned char s1[50] = "qwerty qwerty";
// 	unsigned char s2[50] = "abcdef abcdef";
// 	size_t n = 3;

// 	printf("%d\n", ft_memcmp(s1, s2, n));
// }