/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjaum <akjaum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by jneris-d          #+#    #+#             */
/*   Updated: 2025/11/03 14:58:15 by akjaum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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