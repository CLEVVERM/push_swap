/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/07 14:06:50 by msotnych      #+#    #+#                 */
/*   Updated: 2026/10/07 18:48:57 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	l;
	size_t	a;

	a = 0;
	l = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start > l)
		return (ft_strdup(""));
	if (l - start < len)
		len = l - start;
	res = malloc (len + 1 * sizeof(char ));
	if (!res)
		return (NULL);
	while (a < len && s[a + start])
	{
		res[a] = s[a + start];
		a++;
	}
	res[a] = '\0';
	return (res);
}

// int main(void)
// {
// 	char *s = "lorem ipsu";
// 	int c = 0;
// 	size_t g = 10;
// 	printf("%s\n", ft_substr(s, c, g));
// }