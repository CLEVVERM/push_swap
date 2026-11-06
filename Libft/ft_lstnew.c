/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/12 15:46:31 by msotnych      #+#    #+#                 */
/*   Updated: 2026/10/12 16:46:21 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new -> content = content;
	new -> next = NULL;
	return (new);
}

// int main(void)
// {
// 	t_list *new;
// 	char c[] = "ugvei";
// 	new = ft_lstnew(c);
// 	printf("%s\n", (char *)new -> content);
// }