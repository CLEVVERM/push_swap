/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   medium_sort.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/17 15:27:59 by msotnych      #+#    #+#                 */
/*   Updated: 2026/11/17 19:12:46 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bucket_sort(t_data *data)
{
	int	min;
	int	max;
	int	counter;
	int	finish;

	finish = data->a.size;
	min = 0;
	max = 9;
	counter = 0;
	while(data->a.top != NULL)
	{
		if (data->a.top->index >= min && data->a.top->index <= max)
		{
			pb(data);
			counter++;
		}

		if (counter > max)
		{
			min = min + 10;
			max = max + 10;
		}
		else
			ra(data);
	}
}
void	sort_b(t_data *data)
{
	int	max;
	int	step;
	t_node *curr;

	step = 0;
	max = data->b.size - 1;
	curr = data->b.top;
	while(data->b.top != NULL)
	{
		if (curr->index == max)
		{
			while (data->b.top->index != max)
				rb(data);
			pa(data);
			max--;
			while(step-- -1)
				rrb(data);
		}
		step = 0;
		curr = data->b.top;
		while (curr->index != max)
		{
			curr = curr->next;
			step++;
		}
	}
}