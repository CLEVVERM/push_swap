/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/01 14:30:42 by msotnych      #+#    #+#                 */
/*   Updated: 2026/10/02 17:56:59 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *) dest;
	b = (unsigned char *) src;
	if (!src && !dest)
		return (dest);
	while (n--)
	{
		*a = *b;
		a++;
		b++;
	}
	return (dest);
}

// int main(void)
// {
// 	unsigned char b[50] ="";
// 	size_t n = 3;
// 	unsigned char a[50] = "xxxxxxxxxxx";
// 	printf("%s\n", (char*) ft_memcpy(b, a, n));
// 	printf("%s\n", (char*) memcpy(b, a, n));
// }