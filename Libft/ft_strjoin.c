/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/07 18:49:35 by msotnych      #+#    #+#                 */
/*   Updated: 2026/10/08 14:44:18 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*res;
	size_t			l1;
	size_t			l2;
	unsigned int	c;
	unsigned int	b;

	b = 0;
	c = 0;
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	res = malloc (l1 + l2 + 1 * sizeof(char ));
	if (!res)
		return (NULL);
	while (c < l1)
	{
		res[c] = s1[c];
		c++;
	}
	while (b < l2)
	{
		res[b + c] = s2[b];
		b++;
	}
	res[b + c] = '\0';
	return (res);
}

// int main(void)
// {
// 	char *a = "qwerty";
// 	char *b = "abcde";
// 	printf ("%s\n", ft_strjoin(a, b));
// }