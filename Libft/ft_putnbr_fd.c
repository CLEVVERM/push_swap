/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: msotnych <msotnych@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/12 13:25:09 by msotnych      #+#    #+#                 */
/*   Updated: 2026/10/12 13:59:43 by msotnych      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
	}
	ft_putchar_fd(nb % 10 + '0', fd);
}

// #include <fcntl.h>

// int main(void)
// {	
// 	int n = -3546556;
// 	int fd;
// 	fd = open("test.txt", O_WRONLY);
// 	ft_putnbr_fd(n, fd);
// 	close(fd);
// }
