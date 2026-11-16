/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations2.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/11 15:37:28 by msotnych      #+#    #+#                 */
/*   Updated: 2026/11/16 18:25:24 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data *data)
{
	if (data->a.size < 2)
		return ;
	rotate(&data->a);
	data->ra_c++;
	write(1, "ra\n", 3);
}

void	rb(t_data *data)
{
	if (data->b.size < 2)
		return ;
	rotate(&data->b);
	data->rb_c++;
	write(1, "rb\n", 3);
}

void	rr(t_data *data)
{
	if ( data->a.size < 2 || data->b.size < 2)
		return ;
	rotate(&data->a);
	rotate(&data->b);
	data->rr_c++;
	write(1, "rr\n", 3);
}

void	rra(t_data *data)
{
	if (data->a.size < 2)
		return ;
	rrotate(&data->a);
	data->rra_c++;
	write(1, "rra\n", 4);
}

void	rrb(t_data *data)
{
	if (data->b.size < 2)
		return ;
	rrotate(&data->b);
	data->rrb_c++;
	write(1, "rrb\n", 4);
}
