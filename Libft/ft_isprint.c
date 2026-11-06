/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/28 17:55:56 by msotnych      #+#    #+#                 */
/*   Updated: 2026/09/29 12:40:03 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

//  int	main(void)
// {
// 	char q = 'p';
// 	char w = '\n';
// 	char e = '3';
// 	char r = ' ';
// 	printf("%c %d\n", q, ft_isprint(q));
// 	printf("%c %d\n", w, ft_isprint(w));
// 	printf("%c %d\n", e, ft_isprint(e));
// 	printf("%c %d\n", r, ft_isprint(r));
// }