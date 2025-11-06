/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jneris-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:51:18 by jneris-d          #+#    #+#             */
/*   Updated: 2025/11/06 15:51:20 by jneris-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Converte ascii para int
#include "libft.h"

int	ft_atoi(const char *n)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while ((n[i] >= 9 && n[i] <= 13) || n[i] == ' ')
		i++;
	if (n[i] == '+' || n[i] == '-')
	{
		if (n[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (n[i] >= '0' && n[i] <= '9')
	{
		result = result * 10 + (n[i] - '0');
		i++;
	}
	return (result * sign);
}
