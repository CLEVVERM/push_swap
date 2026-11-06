/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/09 17:37:32 by msotnych      #+#    #+#                 */
/*   Updated: 2026/10/09 18:54:46 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*r;
	unsigned int	c;
	int				l;

	c = 0;
	if (!s || !f)
		return (NULL);
	l = ft_strlen(s);
	r = malloc(l + 1 * sizeof(char ));
	if (!r)
		return (NULL);
	while (s[c] != '\0')
	{
		r[c] = (*f)(c, s[c]);
		c++;
	}
	r[c] = '\0';
	return (r);
}

// char test_transform(unsigned int a, char c)
// { 
// (void) a;
//  if (c >= 'a' && c <= 'z')
//  	return (c - 32); 
// return (c);
// }
// int main(void)
// {
// 	char *str = "hello world!"; 
// 	printf("%s\n", ft_strmapi(str, test_transform));
// }
