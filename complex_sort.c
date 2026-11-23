/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   complex_sort.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/18 17:38:38 by msotnych      #+#    #+#                 */
/*   Updated: 2026/11/23 18:10:41 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int digit_counter(int size)
{
	int amount;
	int max;
	
	max = size - 1;
	amount = 0;
	while (max > 0)
	{
		max = max / 10;
		amount++;
	}
	return (amount);
}

static void push_to_b(t_data *data, int digit, int exp)
{
	int size;
	int amount;

	amount = 0;
	size = data->a.size;
	while (amount < size)
	{
		if((data->a.top->index / exp) % 10 == digit)
			pb(data);
		else 
			ra(data);
		amount++;
	}
	
}

void	radix_sort(t_data *data)
{
	int amount;
	int passed;
	int exp;
	int digit;

	amount = digit_counter(data->a.size);
	passed = 0;
	exp = 1;
	while (passed < amount)
	{
		digit = 0;
		while (digit < 10)
		{
			push_to_b(data, digit, exp);
			digit++;
		}
		while (data->b.size > 0)
			pa(data);
		exp = exp * 10;
		passed++;
	}
	
	  
}