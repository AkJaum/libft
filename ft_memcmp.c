/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jneris-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:52:33 by jneris-d          #+#    #+#             */
/*   Updated: 2025/11/06 15:52:35 by jneris-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Compara dois blocos de memoria até n bytes
#include "libft.h"

int	ft_memcmp(const void *p1, const void *p2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;

	ptr1 = (unsigned char *)p1;
	ptr2 = (unsigned char *)p2;
	i = 0;
	while (i < n)
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (0);
}
