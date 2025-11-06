/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jneris-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:52:16 by jneris-d          #+#    #+#             */
/*   Updated: 2025/11/06 15:52:18 by jneris-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Converte uma variavel int para ascii
#include "libft.h"

//Conta quantos digitos tem a int
static int	ft_countint(long n)
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
