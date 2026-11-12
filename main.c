/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/09 16:57:02 by msotnych      #+#    #+#                 */
/*   Updated: 2026/11/12 18:46:42 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static int group()
{
	
}

int main(int argc, char *argv[])
{
	t_data data;

	ft_bzero(&data, sizeof(t_data));
	
	if (argc < 2)
		return (0);
	if (pars(argc, argv, &data) == 0)
		free_both(&data.a, &data.b);
	ft_printf("size: %d\n", data.a.size);
	ft_printf("strategy:%d\n", data.strategy);
	free_group(&data.a);
	free_group(&data.b);
	return(1);
}