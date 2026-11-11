/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations2.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/11 15:37:28 by msotnych      #+#    #+#                 */
/*   Updated: 2026/11/11 15:38:46 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra(t_group *a)
{
	if (!a || a->size < 2)
		return ;
	rotate(a);
	write(1, "ra\n", 3);
}

void rb(t_group *b)
{
	if (!b || b->size < 2)
		return ;
	rotate(b);
	write(1, "rb\n", 3);
}

void rr(t_group *a, t_group *b)
{
	if (!b || !a || a->size < 2 || b->size < 2)
		return ;
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}

void rra(t_group *a)
{
	if (!a || a->size < 2)
		return ;
	rrotate(a);
	write(1, "rra\n", 4);
}

void rrb(t_group *b)
{
	if (!b || b->size < 2)
		return ;
	rrotate(b);
	write(1, "rrb\n", 4);
}
