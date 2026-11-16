/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations1.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/10 14:56:09 by msotnych      #+#    #+#                 */
/*   Updated: 2026/11/16 17:59:25 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data)
{
	if (data->a.size < 2)
		return ;
	swap(&data->a);
	data->sa_c++;
	write(1, "sa\n", 3);
}

void	sb(t_data *data)
{
	if (data->b.size < 2)
		return ;
	swap(&data->b);
	data->sb_c++;
	write(1, "sb\n", 3);
}

void	ss(t_data *data)
{
	if (data->a.size < 2 || data->b.size < 2)
		return ;
	swap(&data->a);
	swap(&data->b);
	data->ss_c++;
	write(1, "ss\n", 3);
}

void	pa(t_data *data)
{
	if (data->b.size < 1)
		return ;
	push_to_other(&data->b, &data->a);
	data->pa_c++;
	write(1, "pa\n", 3);
}

void	pb(t_data *data)
{
	if (data->a.size < 1)
		return ;
	push_to_other(&data->a, &data->b);
	data->pb_c++;
	write(1, "pb\n", 3);
}
