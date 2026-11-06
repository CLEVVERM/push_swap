/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/08 14:44:49 by msotnych      #+#    #+#                 */
/*   Updated: 2026/10/08 16:48:27 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*res;
	size_t			f;
	size_t			l;
	unsigned int	a;

	f = 0;
	a = 0;
	l = ft_strlen(s1);
	if (!set || !s1)
		return (NULL);
	while (s1[f] && ft_strchr(set, s1[f]))
		f++;
	while (l > f && ft_strchr(set, s1[l - 1]))
		l--;
	res = malloc(l - f + 1 * sizeof(char ));
	if (!res)
		return (NULL);
	while (l > f)
	{
		res[a] = s1[f];
		a++;
		f++;
	}
	res[a] = '\0';
	return (res);
}

// int main(void)
// {
// 	char *s = "ssssssqwertyssss";
// 	char *a = "s";
// 	printf("%s\n", ft_strtrim(s, a));
// }