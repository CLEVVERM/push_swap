/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_utils_1.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/05 17:54:29 by msotnych      #+#    #+#                 */
/*   Updated: 2026/11/10 19:14:55 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *new_one(int data)
{
	t_node *new;
	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	new->prew = NULL;
	new->index = -1;
	return (new);
}

void free_group(t_group *group)
{
	t_node *curr;
	t_node *temp;

	if (!group || group == NULL)
		return ;
	curr = group->top; 
	while (curr != NULL)
	{
		temp = curr -> next;
		free(curr);
		curr = temp;
	}
	group->size = 0;
	group->top = NULL;
	group->bottom = NULL;
}

void add_bottom(t_group *group, t_node *node)
{
	if (!group -> top)
	{
		group -> top = node;
		group -> bottom = node;
		node -> next = NULL;
	}
	else
	{
		group -> bottom -> next = node;
		node -> prew = group -> bottom;
		group -> bottom = node;
	}
	group -> size++;	
}

void free_both(t_group *a, t_group *b)
{
	free_group (a);
	free_group (b);
	write(2, "Error\n", 6);
	exit(1);
}

void swap(t_group *group)
{
	t_node *temp;
	
	if (group == NULL || group->size < 2)
		return ;
	temp = group->top;
	group->top = group->top->next;
	group->top->next = temp;
	temp = group->top->index;
	group->top->index = group->top->next->index;
	group->top->next->index = temp;
}
