/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isanum.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/28 16:51:53 by msotnych      #+#    #+#                 */
/*   Updated: 2026/10/01 10:14:14 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else if (c >= '0' && c <= '9')
	{
		c++;
	}
	else
	{
		return (0);
	}
	return (1);
}

// int	main(void)
// {
// 	char str1[] = "p";
// 	char str2[] = "P";
// 	char str3[] = "1";
// 	char str4[] = " ";
// 	printf("%s %d\n", str1, ft_isanum(str1[0]));
// 	printf("%s %d\n", str2, ft_isanum(str2[0]));
// 	printf("%s %d\n", str3, ft_isanum(str3[0]));
// 	printf("%s %d\n", str4, ft_isanum(str4[0]));
// }	
