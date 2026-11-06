/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/06 19:27:43 by msotnych      #+#    #+#                 */
/*   Updated: 2026/10/07 14:01:54 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*res;
	size_t	l;
	size_t	a;

	a = 0;
	l = ft_strlen(s);
	res = malloc (l + 1);
	if (!res)
	{
		return (NULL);
	}
	while (a < l + 1)
	{
		res[a] = s[a];
		a++;
	}
	return (&(*res));
}

// int main(void)
// {
// 	const char *s = "qwerty uyu mjm\n";
// 	printf("%s\n", ft_strdup(s));
// }