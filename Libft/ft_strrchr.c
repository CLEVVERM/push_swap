/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/02 13:45:09 by msotnych      #+#    #+#                 */
/*   Updated: 2026/10/02 19:34:46 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				a;
	unsigned char	b;

	b = c;
	a = 0;
	while (s[a] != '\0')
		a++;
	while (a >= 0)
	{
		if (s[a] == b)
			return ((char *)&s[a]);
		a--;
	}
	if (b == '\0')
		return ((char *)&s[a]);
	else if (s[a] == b)
		return ((char *)&s[a]);
	return (NULL);
}

// int main(void)
// {
// 	const char* s = "sdvwse fvs";
// 	char c = ' ';
// 	printf("%s\n", ft_strrchr(s, c));
// 	printf("%s\n", strrchr(s, c));
// }