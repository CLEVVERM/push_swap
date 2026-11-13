/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/09 16:57:02 by msotnych      #+#    #+#                 */
/*   Updated: 2026/11/13 13:23:21 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_group(t_group *group)
{
	t_node *curr;
	if (!group || group == NULL)
		return ;
	curr = group->top;
	while (curr != NULL)
	{
		ft_printf("%d ", curr->data);
		curr = curr->next;
	}
	ft_printf("%c", '\n');
}

int main(int argc, char *argv[])
{
	t_data data;

	ft_bzero(&data, sizeof(t_data));
	
	if (argc < 2)
		return (0);
	if (pars(argc, argv, &data) == 0)
		free_both(&data.a, &data.b);
	ft_printf("size: %d\n", data.a.size);
	ft_printf("strategy:%d\n", data.strategy);
	print_group(&data.a);
	print_group(&data.b);
	free_group(&data.a);
	free_group(&data.b);
	return(1);
}