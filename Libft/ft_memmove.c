/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/01 15:58:12 by msotnych      #+#    #+#                 */
/*   Updated: 2026/10/06 19:13:25 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *) dest;
	b = (unsigned char *) src;
	if ((!src && !dest) || src == dest)
		return (dest);
	if (a < b)
	{
		while (n--)
		{
			*a = *b;
			a++;
			b++;
		}
	}
	else
	{
		while (n--)
		{
			a[n] = b[n];
		}
	}
	return (dest);
}

// int main(void)
// {
// 	unsigned char b[50] ="12345678";
// 	size_t n = 4;
// 	unsigned char a[50] = "qwerty";
// 	printf("%s\n", (char*) ft_memmove(b, a, n));
// }