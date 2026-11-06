/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/03 14:36:02 by msotnych      #+#    #+#                 */
/*   Updated: 2026/11/06 13:20:17 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "Libft/libft.h"
# include "ft_printf/ft_printf.h"


typedef struct s_node
{
	int data;
	int index;
	struct s_node *next;
	struct s_node *prew;
}	t_node;

typedef struct s_group
{
	t_node *top;
	int size;
	t_node *bottom;
}	t_group;

typedef struct s_insides
{
	
};

t_node new_one(int data);
void sa(t_group *a);
void sb(t_group *b);
void pa(t_group *a,t_group *b);
void pb(t_group *a,t_group *b);
void ra(t_group *a);
void rb(t_group *b);
void rr(t_group *a,t_group *b);
void rra(t_group *a);
void rrb(t_group *b);
void rrr(t_group *a,t_group *b);
#endif