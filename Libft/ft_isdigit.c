/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/28 16:35:39 by msotnych      #+#    #+#                 */
/*   Updated: 2026/09/29 17:18:23 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		c++;
	}
	else
	{
		return (0);
	}
	return (1);
}

//  int	main(void)
// {
// 	char str1[] = "p";
// 	char str2[] = "4";
// 	char str3[] = "k";
// 	char str4[] = " ";
// 	printf("%s %d\n", str1, ft_isdigit(str1[0]));
// 	printf("%s %d\n", str2, ft_isdigit(str2[0]));
// 	printf("%s %d\n", str3, ft_isdigit(str3[0]));
// 	printf("%s %d\n", str4, ft_isdigit(str4[0]));
// }	