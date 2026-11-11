/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   disorder.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmolotko <mmolotko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/11 11:02:15 by mmolotko      #+#    #+#                 */
/*   Updated: 2026/11/11 12:23:43 by mmolotko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	total_pairs(t_group *a)
{
	int	pairs;
	int	cunt;

	cunt = 0;
	pairs = 0;
	while (a->top->next != NULL)
	{
		cunt++;
		a->top->next;
	}
	pairs = cunt * (cunt - 1);
	printf("total of pairs is: %d\n", pairs);
	return (pairs);
}

int	total_mistakes(t_group *a)
{
	int		mistakes;
	int 	data;
	t_node	*temp;

	data = a->top->data;
	mistakes = 0;
	while (?)
	{
		while (temp->data != NULL)
		{
			temp->data = a->top->next->data;
			if (data > temp->data)
				mistakes++;
		}
		data = a->top->next->data;
	}
	printf("total of mistakes is: %d\n", mistakes);
	return (mistakes);
}
double	dissorder(t_group *a)
{
	double dissorder;

	dissorder = total_mistakes(a) / total_pairs(a);
	printf("The dissorder is: %f\n", dissorder);
	return(dissorder);
}