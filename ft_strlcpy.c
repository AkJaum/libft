/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jneris-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:54:13 by jneris-d          #+#    #+#             */
/*   Updated: 2025/11/06 15:54:15 by jneris-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Copia o conteudo de uma string para a outra e retorna o tamanho da string 
//copiada
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t siz )
{
	size_t	i;

	i = 0;
	if (siz != 0)
	{
		while (i < siz - 1 && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[i] != '\0')
		i++;
	return (i);
}
