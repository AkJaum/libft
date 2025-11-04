/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jneris-d <tbpjaum@outlook.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by jneris-d          #+#    #+#             */
/*   Updated: 0000/00/00 00:00:00 by jneris-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countint(int n)
{
	int	count;

	count = 1;
	if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n >= 10)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*asciin;
	long	nbr;
	int		count;

	nbr = n;
	count = ft_countint(nbr);
	if (nbr < 0)
		nbr = -nbr;
	asciin = malloc(count + 1);
	if (!asciin)
		return (NULL);
	asciin[count] = '\0';
	while (count > 0)
	{
		count--;
		asciin[count] = (nbr % 10) + '0';
		nbr = nbr / 10;
		if (n < 0 && count == 0)
			asciin[0] = '-';
	}
	return (asciin);
}
