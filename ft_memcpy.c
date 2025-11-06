/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jneris-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:52:41 by jneris-d          #+#    #+#             */
/*   Updated: 2025/11/06 15:52:43 by jneris-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Copia todos os bytes de um vetor para outro
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	unsigned char	*str_dest;
	unsigned char	*str_src;
	size_t			i;

	str_dest = (unsigned char *)dest;
	str_src = (unsigned char *)src;
	i = 0;
	while (i < num)
	{
		str_dest[i] = str_src[i];
		i++;
	}
	return (dest);
}
