/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/01 10:18:33 by msotnych      #+#    #+#                 */
/*   Updated: 2026/10/02 17:51:38 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*a;

	a = (unsigned char *) s;
	while (n--)
	{
		*a = '\0';
		a++;
	}
}

// int main(void)
// {
// 	unsigned char a[50] ="y qweqwertrty";
// 	size_t n = 5;
// 	ft_bzero(a,n);
// 	printf("%s",a + n);
// }