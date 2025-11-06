/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jneris-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:53:38 by jneris-d          #+#    #+#             */
/*   Updated: 2025/11/06 15:53:40 by jneris-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Localiza a primeira ocorrencia de um caractere especifico na string
#include "libft.h"

char	*ft_strchr(const char *str, int search_str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)search_str)
			return ((char *)str + i);
		i++;
	}
	if ((char)search_str == '\0')
		return ((char *) str + i);
	return (NULL);
}
