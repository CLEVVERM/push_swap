/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/02 11:38:23 by msotnych      #+#    #+#                 */
/*   Updated: 2026/10/02 19:03:44 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		a;
	char	b;

	b = c;
	a = 0;
	while (s[a] != '\0')
	{
		if (s[a] == b)
			return ((char *)&s[a]);
		a++;
	}
	if (s[a] == b)
		return ((char *)&s[a]);
	return (0);
}

// int main(void)
// {
// 	const char* s = "qwerty asdfg zxcvb";
// 	int c = 'e';
// 	printf("%p\n", ft_strchr(s, c));
// }