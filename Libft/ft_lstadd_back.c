/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/13 11:56:57 by msotnych      #+#    #+#                 */
/*   Updated: 2026/10/13 14:23:53 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*content;

	if (!lst || !new)
		return ;
	if (*lst != NULL)
	{
		content = ft_lstlast(*lst);
		content -> next = new;
	}
	else
		*lst = new;
}

// int main(void)
// {
// 	t_list *old;
// 	t_list *new;
// 	old = ft_lstnew("qwerty");
// 	new = ft_lstnew("zxcv");
// 	ft_lstadd_back(&old, new);
// 	ft_lstadd_back(&old, new);
// 	printf("%s\n", (char *)old -> content);
// } 