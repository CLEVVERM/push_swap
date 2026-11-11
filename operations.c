/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/10 14:56:09 by msotnych      #+#    #+#                 */
/*   Updated: 2026/11/10 14:56:10 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_group *a)
{
	if (!a || a->size < 2)
		return ;
	swap(a);
	write(1, "sa\n", 3);
}

void sb(t_group *b)
{
	if (!b || b->size < 2)
		return ;
	swap(b);
	write(1, "sb\n", 3);
}

void ss(t_group *a, t_group *b)
{
	if (!a || !b || a->size < 2 || b->size < 2)
		return ;
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}

void pa(t_group *a, t_group *b)
{
	if (!a || !b || b->size < 1)
		return ;
	push_to_other(b, a);
	write(1, "pa\n", 3);
}

void pb(t_group *a, t_group *b)
{
	if (!a || !b || a->size < 1)
		return ;
	push_to_other(a, b);
	write(1, "pb\n", 3);
}

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

void rrr(t_group *a, t_group *b)
{
	if (!b || !a || a->size < 2 || b->size < 2)
		return ;
	rrotate(a);
	rrotate(b);
	write(1, "rrr\n", 4);
}