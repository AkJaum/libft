/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jneris-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:53:17 by jneris-d          #+#    #+#             */
/*   Updated: 2025/11/06 15:53:19 by jneris-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Printa um número na saida especificada em fd
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		write(fd, "-", 1);
		nbr = nbr * -1;
	}
	if (nbr >= 10)
	{
		ft_putnbr_fd(nbr / 10, fd);
		c = (nbr % 10) + '0';
		write(fd, &c, 1);
	}
	if (nbr < 10)
	{
		c = nbr + '0';
		write(fd, &c, 1);
	}
}

/*void	ft_putnbr(int n)
{
        char    c;
        long    nbr;

        nbr = n;
        if (nbr < 0)
                write(1, "-", 1);
        if (nbr >= 10)
        {
		ft_putnbr(nbr / 10);
                c = (nbr % 10) + '0';
                write(1, &c, 1);
        }
        if (nbr < 10)
        {
                c = nbr + '0';
                write(1, &c, 1);
        }
}

int	main(void)
{
	ft_putnbr(1200);
}*/
