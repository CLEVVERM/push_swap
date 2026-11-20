/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/09 16:57:02 by msotnych      #+#    #+#                 */
/*   Updated: 2026/11/20 15:55:28 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static	void	sorted_message(t_data *data)
{
	if(sorted(&data->a))
		ft_printf("stack is sorted\n");
	else
		ft_printf("stack is not sorted\n");
}

void	print_group(t_group *group)
{
	t_node	*curr;

	if (!group || group == NULL)
		return ;
	curr = group->top;
	while (curr != NULL)
	{
		ft_printf("%d ", curr->data);
		curr = curr->next;
	}
	ft_printf("%c", '\n');
}

int	main(int argc, char *argv[])
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	
	if (argc < 2)
		return (0);
	if (pars(argc, argv, &data) == 0)
		free_both(&data.a, &data.b);
	ft_printf("size: %d\n", data.a.size);
	ft_printf("strategy:%d\n", data.strategy);
	print_group(&data.a);
	print_group(&data.b);
	sorted_message(&data);
	index_for_sorting(&data.a);
	data.disorder = better_dissorder(&data.a);
	printf("disorder: %f\n", data.disorder);
	manager_of_strategy(&data);
	// po sabjkty nam nado vivodit infy ob oshike i disorder i td v stdrr
	// toest, nyjno izmenit ft_printf 
	sorted_message(&data);
	data.disorder = better_dissorder(&data.a);
	printf("disorder: %f\n", data.disorder);
	//ЗАПУСКАТЬ ТАК: СНАЧАЛА make,  ПОТОМ  ./push_swap 2 34 5 77 6
	free_group(&data.a);
	free_group(&data.b);
	return(1);
}

//Elsi vdrug zahotim cherez random chsila testitj.

// int	main(void)
// {
// 	t_group a;
// 	int		min;
// 	int		max;
// 	int		size;

// 	min = -500;
// 	max = 500;
// 	size = 0;
// 	a.top = NULL;
// 	a.bottom = NULL;
// 	a.size = 0;
// 	srand(time(NULL));
// 	while(size++ < 100)
// 	{
// 		add_bottom (&a, new_one(rand() % (max - min + 1) + min));
// 	}
// }