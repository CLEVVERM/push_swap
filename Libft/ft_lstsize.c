/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/12 18:04:51 by msotnych      #+#    #+#                 */
/*   Updated: 2026/10/13 11:47:44 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	c;

	c = 0;
	while (lst != NULL)
	{
		c++;
		lst = lst -> next;
	}
	return (c);
}

// int main(void)
// {
// 	t_list *one;
// 	t_list *two;
// 	t_list *three;
// 	int c;
// 	one = ft_lstnew("one");
// 	two = ft_lstnew("two");
// 	three = ft_lstnew("three");
// 	one -> next = two;
// 	two -> next = three;
// 	three = ft_lstnew("three");
// 	c = ft_lstsize(one);
// 	printf("%d\n", c);
// }