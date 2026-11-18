/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/12 17:57:53 by msotnych      #+#    #+#                 */
/*   Updated: 2026/11/18 18:29:05 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void adaptive_sort(t_data *data)
{
	if (data->a.size == 3 && data->disorder != 0)
		sort_three(data);
	else if (data->a.size == 2 && data->disorder != 0)
		sa(data);
	// else if (data->disorder <= 0.2 && data->disorder != 0)
	// 	ss_sort(data);
	else if (0.2 <= data->disorder <= 0.5)
		bucket_sort(data);
	// else if (data->disorder >= 0.5)
	// 	 radix_sort(data);
}

void	manager_of_strategy(t_data *data)
{
	if (data->strategy == 1)
		selection_sort(data);
	else if (data->strategy == 2)
		bucket_sort(data);
	// else if (data->strategy == 3)
	// 	radix_sort(data);
	else if (data->strategy == 0)
		adaptive_sort(data);
}



void	sort_three(t_data *data)
{
	if (data->a.top->index == 1)
	{
		ra(data);
		sa(data);
		rra(data);
	}
	else if (data->a.bottom->index == 1)
	{		
	if (data->a.top->index == 3)
		{
			ra(data);
			ra(data);
		}
		else
		{	
			sa(data);
			ra(data);
			ra(data);
		}
	}
	else
	{
		if (data->a.top->index == 3)
		{
			rra(data);
			sa(data);
			rra(data);
		}
		else
		{
			rra(data);
			rra(data);
		}
	}
}
