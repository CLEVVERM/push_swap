/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   super_simple_sort.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/18 18:00:14 by msotnych      #+#    #+#                 */
/*   Updated: 2026/11/20 15:48:48 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_data *data)
{
	t_node *curr;
	int max;

	max = 0;
	curr = data->a.top;
	while (curr != NULL)
	{
		if (curr->index > max)
			max = curr->index;
		curr= curr->next;
	}
	if (data->a.top->index == max)
		ra(data);
	else if(data->a.top->next->index == max) 
		rra(data);
	if (data->a.top->index > data->a.top->next->index && data->a.bottom->index == max)
		sa(data);
}

static int	find_pos(t_group *group, int index)
{
	int		pos;
	t_node	*curr;

	curr = group->top;
	pos = 0;
	while (curr != 0 && curr->index != index)
	{
		curr = curr->next;
		pos++;
	}
	return (pos);
}


void	sort_four_five(t_data *data)
{
	int index_to_find;
	int pos;

	index_to_find = 0;
	while (data->a.size > 2)
	{
		pos = find_pos(&data->a, index_to_find);
		while (data->a.top->index != index_to_find)
		{
			if (pos <= data->a.size / 2)
				ra(data);
			else
				rra(data);
		}
		pb(data);
		index_to_find++;
	}
	if (data->a.top->index > data->a.top->next->index)
		sa(data);
	while (data->b.size != 0)
		pa(data);
}
