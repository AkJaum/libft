/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jneris-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:51:33 by jneris-d          #+#    #+#             */
/*   Updated: 2025/11/06 15:51:35 by jneris-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Malloc cria o buffer com lixo de memória dentro, a calloc atribui 0 para todos
//os bytes do buffer
#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	unsigned char	*arr;
	size_t			i;

	i = 0;
	if (n != 0 && size > SIZE_MAX / n)
		return (NULL);
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
