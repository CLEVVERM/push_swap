/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/12 17:57:53 by msotnych      #+#    #+#                 */
/*   Updated: 2026/11/25 16:44:53 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void adaptive_sort(t_data *data)
{
	if (data->a.size == 3 && data->disorder != 0){
		sort_three(data);
		data->hardnes = "adaptive / O(n)";
	}
		
	else if ((data->a.size == 4 || data->a.size == 5) && data->disorder != 0){
		sort_four_five(data);
		data->hardnes = "adaptive / O(n)";
	}
	else if (data->a.size == 2 && data->disorder != 0){
		sa(data);
		data->hardnes = "adaptive / O(n)";
	}
		
	else if (0.2 <= data->disorder && data->disorder <= 0.5 && data->a.size > 5){
		bucket_sort(data);
		data->hardnes = "adaptive / O(n√n)";
	}
			
	else if (data->disorder >= 0.5){
		radix_sort(data);
		data->hardnes = "adaptive / O(n log n)";
	}
	else{
		data->hardnes = "adaptive / O(n)";
		radix_sort(data);
	}	
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

void	hardnes_for_bench(t_data *data)
{
	if (data->strategy == 1)
		data->hardnes = "simple / O(n²)";
	else if (data->strategy == 2)
		data->hardnes = "medium / O(n√n)";
	else if (data->strategy == 3)
		data->hardnes = "complex / O(n log n)";
	
}
