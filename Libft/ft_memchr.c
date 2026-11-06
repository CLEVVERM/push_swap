/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/02 15:17:26 by msotnych      #+#    #+#                 */
/*   Updated: 2026/10/02 19:33:56 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*a;
	size_t			b;

	b = 0;
	a = (unsigned char *) s;
	while (b < n)
	{
		if (a[b] == (unsigned char)c)
			return ((void *)&a[b]);
		b++;
	}
	return (0);
}

// int main(void)
// {
// 	const char* s = "qwerty asdfg zxcvb";
// 	int c = 'e';
// 	size_t n = 6;
// 	printf("%p\n", ft_memchr(s, c, n));
// 		printf("%p\n", memchr(s, c, n));
// }
