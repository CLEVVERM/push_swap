/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/13 16:36:36 by msotnych      #+#    #+#                 */
/*   Updated: 2026/10/13 19:13:48 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	void	*content;
	t_list	*nlst;

	if (!lst || !f)
		return (NULL);
	nlst = NULL;
	while (lst != NULL)
	{
		content = f(lst->content);
		new = ft_lstnew(content);
		if (!new)
		{
			del(content);
			ft_lstclear(&nlst, del);
			return (NULL);
		}
		ft_lstadd_back(&nlst, new);
		lst = lst -> next;
	}
	return (nlst);
}

// static void *uppcont(void *content)
// {
// 	char *str;
// 	int c;

// 	c = 0;
// 	str = ft_strdup((char *)content);
// 	while (str[c] != '\0')
// 	{
// 		str[c] = ft_toupper(str[c]);
// 		c++;
// 	}
// 	return ((void *)str);
// }

// static void delcont(void *content)
// {
// 	free(content);
// }

// int main(void)
// {
// 	t_list *first;
// 	t_list *second;
// 	first = NULL;
// 	ft_lstadd_back(&first, ft_lstnew((ft_strdup("first0"))));
// 	ft_lstadd_back(&first, ft_lstnew((ft_strdup("first1"))));
// 	ft_lstadd_back(&first, ft_lstnew((ft_strdup("first2"))));
// 	second = ft_lstmap(first, uppcont, delcont);
// 	printf("%s\n", (char *)second -> content);
// }