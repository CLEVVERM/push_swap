/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstlast.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/13 12:03:12 by msotnych      #+#    #+#                 */
/*   Updated: 2026/10/13 13:03:59 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next != NULL)
	{
		lst = lst -> next;
	}
	return (lst);
}

// int main(void)
// {
// 	t_list *new = NULL;
// 	t_list *old = NULL;
// 	old = ft_lstnew("qwerty");
// 	new = ft_lstnew("weasdf");
// 	old -> next = new;
// 	new = ft_lstlast(new);
// 	printf("%s\n", (char *)old -> content);
// }
