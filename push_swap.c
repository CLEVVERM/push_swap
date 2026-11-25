/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/12 17:57:53 by msotnych      #+#    #+#                 */
/*   Updated: 2026/11/25 13:50:37 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void adaptive_sort(t_data *data)
{
	if (data->a.size == 3 && data->disorder != 0)
		sort_three(data);
	else if ((data->a.size == 4 || data->a.size == 5) && data->disorder != 0)
		sort_four_five(data);
	else if (data->a.size == 2 && data->disorder != 0)
		sa(data);
	else if (0.2 <= data->disorder && data->disorder <= 0.5 && data->a.size > 5)
			bucket_sort(data);
	else if (data->disorder >= 0.5)
		 radix_sort(data);
	else
		radix_sort(data);
}

void	manager_of_strategy(t_data *data)
{
	if (data->strategy == 1)
		selection_sort(data);
	else if (data->strategy == 2)
			bucket_sort(data);
	else if (data->strategy == 3)
		radix_sort(data);
	else if (data->strategy == 0)
		adaptive_sort(data);
}


