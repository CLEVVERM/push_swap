/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/29 15:59:35 by msotnych      #+#    #+#                 */
/*   Updated: 2026/10/06 19:14:30 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t			b;
	size_t			a;

	b = 0;
	if (!*little)
		return ((char *)big);
	while (b < len && big[b] != '\0')
	{
		a = 0;
		while (big[b + a] == little[a] && (a + b) < len)
		{
			a++;
			if (little [a] == '\0')
				return ((char *)&big[b]);
		}
		b++;
	}
	return (0);
}

// int main(void)
// {
// 	const char* big = "qwzerty asdfg zxcvg";
// 	const char* little = "zxcv";
// 	size_t len = 25;
// 	printf("%s\n", ft_strnstr(big, little, len));
// 		printf("%s\n", ft_strnstr(big, little, len));
// }
