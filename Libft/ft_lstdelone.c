/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdelone.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/13 13:45:06 by msotnych      #+#    #+#                 */
/*   Updated: 2026/10/13 14:22:43 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst -> content)
		del(lst -> content);
	free(lst);
}

// static void delcont(void *content)
// {
// 	free(content);
// }

// int main(void)
// {
// 	t_list *first;
// 	first = ft_lstnew(ft_strdup("first"));
// 	ft_lstdelone(first, delcont);
// 	printf("s\n");
// }