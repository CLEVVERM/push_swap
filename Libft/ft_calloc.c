/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/06 15:44:10 by msotnych      #+#    #+#                 */
/*   Updated: 2026/10/06 19:26:12 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*a;

	a = malloc (nmemb * size);
	if (!a)
		return (NULL);
	ft_bzero (a, nmemb * size);
	return (a);
}

//  int main(void)
//  {
// 	size_t n = 2;
// 	size_t m = 3;
// 	printf("%p\n", ft_calloc(n, m));
//  }