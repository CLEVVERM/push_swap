/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_front.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/12 16:47:54 by msotnych      #+#    #+#                 */
/*   Updated: 2026/10/13 11:47:03 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new -> next = *lst;
	*lst = new;
}

// int main(void)
// {
// 	t_list *old;
// 	t_list *new;
// 	old = ft_lstnew("qwerty");
// 	new = ft_lstnew("zxcv");
// 	ft_lstadd_front(&old, new);
// 	ft_lstadd_front(&old, new);
// 	printf("%s\n", (char *)old -> content);
// } 