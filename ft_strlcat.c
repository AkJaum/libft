/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jneris-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:54:01 by jneris-d          #+#    #+#             */
/*   Updated: 2025/11/06 15:54:02 by jneris-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Concateca duas strings e retorna o tamanho das duas strings juntas
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	ii;
	size_t	lentotal;

	i = 0;
	ii = 0;
	while (dest[i] != '\0')
		i++;
	while (src[ii] != '\0')
		ii++;
	lentotal = ii + i;
	if (size <= i)
		return (size + ii);
	ii = 0;
	while (src[ii] != '\0' && i < size - 1)
	{
		dest[i] = src[ii];
		i++;
		ii++;
	}
	dest[i] = '\0';
	i++;
	return (lentotal);
}
