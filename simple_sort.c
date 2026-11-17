/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simple_sort.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/16 16:38:32 by msotnych      #+#    #+#                 */
/*   Updated: 2026/11/17 15:10:07 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	selection_sort(t_data *data)
{
	int	index;

	index = 0;
	while (data->a.top != NULL)
	{
		if(data->a.top->index == index)
		{
			pb(data);
			index++;
		}
		else
		ra(data);
	}
	while (data->b.top != NULL)
		pa(data);
}