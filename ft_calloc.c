/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjaum <akjaum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by jneris-d          #+#    #+#             */
/*   Updated: 2025/11/03 14:58:33 by akjaum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	unsigned char	*arr;
	size_t			i;

	i = 0;
	arr = malloc(n * size);
	if (!arr)
		return (NULL);
	while (i < (n * size))
	{
		arr[i] = 0;
		i++;
	}
	return (arr);
}
