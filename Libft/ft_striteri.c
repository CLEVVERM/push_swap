/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/09 18:17:48 by msotnych      #+#    #+#                 */
/*   Updated: 2026/10/09 18:55:40 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	c;

	c = 0;
	if (!s || !f)
		return ;
	while (s[c] != '\0')
	{
		f (c, & s[c]);
		c++;
	}
}

// void test_transform(unsigned int a, char *c)
// { 
// (void) a;
//  if (*c >= 'a' && *c <= 'z')
//  	*c = *c - 32; 
// }
// int main(void)
// {
// 	char *str = "hello world!";
// 	ft_striteri(str, test_transform);
// 	printf("%s\n", str);
// }
