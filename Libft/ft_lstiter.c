/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstiter.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/13 15:48:25 by msotnych      #+#    #+#                 */
/*   Updated: 2026/10/13 16:29:08 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		f(lst -> content);
		lst = lst -> next;
	}
}

// static void writecont(void *content)
// {
// 	printf("%s\n", (char *)content);
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
// 	ft_lstiter(first, writecont);
// 	printf("s\n");
// }