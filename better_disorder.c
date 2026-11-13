/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   better_disorder.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmolotko <mmolotko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/11 13:38:39 by mmolotko      #+#    #+#                 */
/*   Updated: 2026/11/13 18:11:39 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	better_dissorder(t_group *a)
{
	double	mistakes;
	double	pairs;
	t_node	*i;
	t_node	*j;

	if (a->size <= 1)
		return (0);
	mistakes = 0;
	pairs = 0;
	i = a->top;
	while (i)
	{
		j = i->next;
		while (j)
		{
			pairs++;
			if (i->data > j->data)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	return (mistakes / pairs);
}
