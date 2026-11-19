/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   super_simple_sort.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/18 18:00:14 by msotnych      #+#    #+#                 */
/*   Updated: 2026/11/19 14:14:56 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
