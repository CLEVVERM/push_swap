/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/09 16:57:02 by msotnych      #+#    #+#                 */
/*   Updated: 2026/11/09 18:00:15 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(void)
{
	t_group  test;
	t_node *curr;
	
	test.top = NULL;
	test.bottom = NULL;
	test.size = 0;
	t_node *node0 = new_one(2);
	add_bottom(&test, node0);
	t_node *node1 = new_one(4);
	add_bottom(&test, node1);
	t_node *node2 = new_one(6);
	add_bottom(&test, node2);
	curr = test.top;
	while (curr != NULL)
	{
		ft_printf("%d ", curr -> data);
		curr = curr -> next;
	}
	ft_printf("%s", "\n");
	curr = test.bottom;
	while (curr!= NULL)
	{
		ft_printf("%d ", curr -> data);
		curr = curr -> prew;
	}
	ft_printf("\n%d", test.size);
}