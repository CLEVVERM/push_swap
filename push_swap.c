/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/12 17:57:53 by msotnych      #+#    #+#                 */
/*   Updated: 2026/11/26 17:57:48 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	adaptive_sort(t_data *data)
{
	if (data->a.size == 3 && data->disorder != 0)
	{
		sort_three(data);
		data->hardnes = "adaptive / O(n)";
	}
	else if ((data->a.size == 4 || data->a.size == 5) && data->disorder != 0)
	{
		sort_four_five(data);
		data->hardnes = "adaptive / O(n)";
	}
	else if (data->a.size == 2 && data->disorder != 0)
	{
		sa(data);
		data->hardnes = "adaptive / O(n)";
	}
	else if (0.2 <= data->disorder && data->disorder <= 0.5 && data->a.size > 5)
	{
		bucket_sort(data);
		data->hardnes = "adaptive / O(n√n)";
	}
	else if (data->disorder >= 0.5)
	{
		radix_sort(data);
		data->hardnes = "adaptive / O(n log n)";
	}
	else
	{
		data->hardnes = "adaptive / O(n²)";
		selection_sort(data);
	}
}

static void	hardnes_for_bench(t_data *data)
{
	if (data->strategy == 1)
		data->hardnes = "simple / O(n²)";
	else if (data->strategy == 2)
		data->hardnes = "medium / O(n√n)";
	else if (data->strategy == 3)
		data->hardnes = "complex / O(n log n)";
}

void	manager_of_strategy(t_data *data)
{
	hardnes_for_bench(data);
	if (data->strategy == 1)
		selection_sort(data);
	else if (data->strategy == 2)
		bucket_sort(data);
	else if (data->strategy == 3)
		radix_sort(data);
	else if (data->strategy == 0)
		adaptive_sort(data);
}
