/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/28 14:56:35 by msotnych      #+#    #+#                 */
/*   Updated: 2026/09/30 17:21:18 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	c;

	c = 0;
	if (n == 0)
		return (0);
	while (s1[c] == s2[c] && c + 1 < n)
	{
		if (s1[c] == '\0')
		{
			return (0);
		}
		c++;
	}
	return ((unsigned char)s1[c] - (unsigned char)s2[c]);
}

// int main(void)
// {
// char *s1;
// char *s2;
// int n;

// n = 3;
// s1 = "\200";
// s2 = "\0 \fb";
// ft_strncmp(s1, s2, n);
// printf("%d\n", ft_strncmp(s1, s2, n));
// printf("%d\n", strncmp(s1, s2, n));
// }