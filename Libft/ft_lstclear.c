/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/13 14:24:43 by msotnych      #+#    #+#                 */
/*   Updated: 2026/10/13 16:26:54 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*new;

	if (!lst || !del)
		return ;
	while (*lst != NULL)
	{
		new = (*lst)-> next;
		ft_lstdelone(*lst, del);
		*lst = new;
	}
	*lst = NULL;
}

// static void delcont(void *content)
// {
// 	free(content);
// }

// int main(void)
// {
// 	t_list *first;
// 	t_list *second;
// 	t_list *third;
// 	first = ft_lstnew(ft_strdup("first"));
// 	second = ft_lstnew(ft_strdup("second"));
// 	third = ft_lstnew(ft_strdup("third"));
// 	first -> next = second;
// 	second -> next = third;
// 	ft_lstclear(&first, delcont);
// 	printf("s\n");
// }