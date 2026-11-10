/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_utils_2.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/10 14:59:12 by msotnych      #+#    #+#                 */
/*   Updated: 2026/11/10 19:39:35 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate(t_group *group)
{
	t_node *temp;
	
	if (group == NULL || group->size < 2)
		return ;
	temp = group->top;
	group->top = group->top->next;
	group->top->prew = NULL;
	group->bottom->next = temp;
	temp->prew = group->bottom;
	temp->next = NULL;
	group->bottom = temp;
}

void rrotate(t_group *group)
{
	t_node *temp;

	if(group == NULL || group->size<2)
		return ;
	temp = group->bottom;
	group->bottom = group->bottom->prew;
	group->bottom->next = NULL;
	group->top->prew = temp;
	temp->prew = NULL;
	temp->next = group->top;
	group->top = temp;
}

void push_to_other(t_group *a, t_group *b)
{
	t_node *temp;

	if (a == NULL || b == NULL || a->size < 1)
		return ;
	temp = a->top;
	a->top = a->top->next;
	if (a->top != NULL)
		a->top->prew = NULL;
	if (a->top == NULL)
		a->bottom = NULL;
	a->size--;
	temp->prew = NULL;
	temp->next = b->top;
	if (b->top != NULL)
		b->top->prew = temp;
	if (b->top = NULL)
		b->bottom = temp;
	b->top = temp;
	b->size++;
}
