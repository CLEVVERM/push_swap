/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   complex_sort.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/18 17:38:38 by msotnych      #+#    #+#                 */
/*   Updated: 2026/11/24 17:58:31 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_data *data)
{
	int amount;
	int passed;
	int i;

	
	amount = data->a.size;
	passed = 0;
	if (amount == 0)
		return;
	
	while (amount >> passed)
	{
		i = 0;
		while (i < amount) 
		{
			if (data->a.top->index >> passed & 1) 
			{
				ra(data);
			} 
			else 
			{
				pb(data);
			}
			i++;
		}
		while (data->b.size > 0)
			pa(data);
		passed++;
	} 
}

012