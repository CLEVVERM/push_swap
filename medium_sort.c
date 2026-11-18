/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   medium_sort.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/17 15:27:59 by msotnych      #+#    #+#                 */
/*   Updated: 2026/11/18 16:43:03 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_b(t_data *data)
{
	int	max;
	int	step;
	t_node *curr;

	max = data->b.size - 1;
	curr = data->b.top;
	while(data->b.top != NULL)
	{
		step = 0;
		while (curr->index != max)
		{
			curr = curr->next;
			step++;
		}
		while (data->b.top->index != max)
		{
			if (step >= data->b.size/2)
				rrb(data);
			else
				rb(data);
		}
	}
}

void	bucket_sort(t_data *data)
{
	int	min;
	int	max;
	int	counter;
	int	size;

	counter = 0;
	if (data->a.size <= 100)
		size = 10;
	else 
		size = 50;
	min = 0;
	max = size - 1;
	while(data->a.top != NULL)
	{
		if (data->a.top->index >= min && data->a.top->index <= max)
		{
			if(min + size/ 2 > data->a.top->index)
			{
				pb(data);
				rb(data);	
			}
			else
			{
				pb(data);
				counter++;
			}
			if (counter > max)
			{
				min = min + size;
				max = max + size;
			}
		}
		else
			ra(data);
	}
	sort_b(data);
}





