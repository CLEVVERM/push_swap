/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isascii.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/28 17:40:46 by msotnych      #+#    #+#                 */
/*   Updated: 2026/09/30 13:45:04 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

// int	main(void)
// {
// 	char str1[] = "p";
// 	char str2[] = "P";
// 	char str3[] = "©";
// 	char str4[] = " ";
// 	printf("%s %d\n", str1, ft_isascii(str1[0]));
// 	printf("%s %d\n", str2, ft_isascii(str2[0]));
// 	printf("%s %d\n", str3, ft_isascii(str3[0]));
// 	printf("%s %d\n", str4, ft_isascii(str4[0]));
// }	