/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/29 16:10:21 by msotnych      #+#    #+#                 */
/*   Updated: 2026/09/29 19:25:12 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	c;
	size_t	a;
	size_t	b;

	c = 0;
	b = 0;
	a = 0;
	while (src[c] != '\0')
		c++;
	while (dst[a] != '\0' && a < size)
		a++;
	if (a >= size)
		return (size + c);
	while (src[b] != '\0' && (a + b + 1 < size))
	{
		dst[a + b] = src[b];
		b++;
	}
	dst[a + b] = '\0';
	return (c + a);
}

// int main(void)
// {
// char dst[] = "blia?";
// char src[] = "bli ahui blia? pizda";

// size_t result = ft_strlcat(dst, src, sizeof(dst));

// printf("%zu\n", result);

// }