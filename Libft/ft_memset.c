/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/29 12:49:44 by msotnych      #+#    #+#                 */
/*   Updated: 2026/10/02 17:51:19 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*a;

	a = (unsigned char *) s;
	while (n--)
	{
		*a = (unsigned char) c;
		a++;
	}
	return (s);
}

// int main(void)
// {
// 	unsigned char a[50] ="ahaha hahah hahaha";
// 	size_t n = 6;
// 	int b = 'x';
// 	printf("%s", (char *)ft_memset(a, b, n));
// }