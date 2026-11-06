/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/08 16:49:06 by msotnych      #+#    #+#                 */
/*   Updated: 2026/10/13 17:59:07 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	freeall(char **arr, size_t cnt)
{
	size_t	a;

	a = 0;
	while (a < cnt)
	{
		free(arr[a]);
		a++;
	}
	free (arr);
	return (0);
}

static int	fill(char **arr, char *s, char c)
{
	size_t	a;
	size_t	first;
	size_t	b;

	a = 0;
	b = 0;
	while (s[a] != '\0')
	{
		if (s[a] != c)
		{
			first = a;
			while (s[a] != c && s[a] != '\0')
				a++;
			arr[b] = ft_substr(s, first, a - first);
			if (!arr[b])
				return (freeall(arr, b));
			b++;
		}
		else
			a++;
	}
	arr[b] = NULL;
	return (1);
}

static int	counter(char const *s, char c)
{
	int				a;
	unsigned int	fl;
	unsigned int	k;

	k = 0;
	a = 0;
	fl = 0;
	while (s[a] != '\0')
	{
		if (s[a] != c && fl == 0)
		{
			fl = 1;
			k++;
		}
		else if (s[a] == c)
			fl = 0;
		a++;
	}
	return (k);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = malloc((counter(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	if (!fill(arr, (char *)s, c))
		return (NULL);
	else
		return (arr);
}

// int main(void)
// {
// 	char s[] = "xxxxxxqwertyXXXXXXhuiXXXXXblia";
// 	char c = 'X';
// 	printf("%s\n", *ft_split(s, c));
// }