/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bench.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/25 16:25:40 by msotnych      #+#    #+#                 */
/*   Updated: 2026/11/26 18:13:04 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_disorder(t_data *data)
{
	int	first2digit;
	int	last2digit;
	int	int_disorder;

	int_disorder = data->disorder * 10000;
	first2digit = int_disorder / 100;
	last2digit = int_disorder % 100;
	ft_putstr_fd("disorder: ", 2);
	ft_putnbr_fd(first2digit, 2);
	ft_putchar_fd('.', 2);
	ft_putnbr_fd(last2digit, 2);
	ft_putchar_fd('%', 2);
	ft_putchar_fd('\n', 2);
}

static void	print_strategy(t_data *data)
{
	ft_putstr_fd("strategy: ", 2);
	if (data->hardnes != NULL)
		ft_putstr_fd(data->hardnes, 2);
	else
		ft_putstr_fd("sorted", 2);
	ft_putchar_fd('\n', 2);
}

static void	print_total_ops(t_data *data)
{
	int	sum;
	int	sum2;

	sum = data->pa_c + data->pb_c + data->sa_c + data-> sb_c + data->ss_c;
	sum2 = sum + data->ra_c + data->rb_c + data->rr_c + data->rra_c + data->rrb_c
	+ data->rrr_c;
	ft_putstr_fd("total_ops: ", 2);
	ft_putnbr_fd(sum2, 2);
	ft_putchar_fd('\n', 2);
}

static void	print_ops(t_data *data)
{
	ft_putstr_fd("sa: ", 2);
	ft_putnbr_fd(data->sa_c, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(data->sb_c, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(data->ss_c, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(data->pa_c, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(data->pb_c, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("ra: ", 2);
	ft_putnbr_fd(data->ra_c, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(data->rb_c, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(data->rr_c, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(data->rra_c, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(data->rrb_c, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(data->rrr_c, 2);
	ft_putchar_fd('\n', 2);
}

void	print_bench(t_data *data)
{
	print_disorder(data);
	print_strategy(data);
	print_total_ops(data);
	print_ops(data);
}
