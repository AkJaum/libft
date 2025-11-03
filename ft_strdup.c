/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjaum <akjaum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by jneris-d          #+#    #+#             */
/*   Updated: 2025/11/03 14:58:56 by akjaum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int	size;
	int	i;
	char	*sdest;

	size = 0;
	i = 0;
	while (str[size] != '\0')
		size++;
	sdest = malloc(size + 1);
	if (!sdest)
		return (NULL);
	while (i < size)
	{
		sdest[i] = str[i];
		i++;
	}
	sdest[i] = '\0';
	return (sdest);
}
