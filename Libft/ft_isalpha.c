/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalpha.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/28 16:30:46 by msotnych      #+#    #+#                 */
/*   Updated: 2026/09/30 16:36:30 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

// int main(void)
// {
//  printf(" %d\n", ft_isalpha('a'));
//  printf(" %d\n", ft_isalpha('Z'));
//  printf(" %d\n", ft_isalpha('5'));
//  printf(" %d\n", isalpha('T'));
// }