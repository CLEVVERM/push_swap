/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/12 14:05:58 by msotnych      #+#    #+#                 */
/*   Updated: 2026/10/12 15:02:51 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	a;
	unsigned int	b;

	a = 0;
	b = 0;
	while (src[b] != '\0')
		b++;
	if (size == 0)
		return (b);
	while (src[a] != '\0' && (size - 1) > a)
	{
		dst[a] = src[a];
		a++;
	}
	dst[a] = '\0';
	return (b);
}

// int main(void)
// {
// 	char ds[50] = "";
// 	char sr[] = "qwerty ytrewq";
// 	size_t n = 5;
// 	printf("%zu\n", ft_strlcpy(ds, sr, n));
// }