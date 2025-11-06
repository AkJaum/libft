/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jneris-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:54:44 by jneris-d          #+#    #+#             */
/*   Updated: 2025/11/06 15:54:45 by jneris-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Encontra e retorna a primeira ocorrencia de s_str dentro de str
#include "libft.h"

char	*ft_strnstr(const char *str, const char *s_str, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!s_str[0])
		return ((char *)str);
	while (str[i] != '\0' && i < len)
	{
		j = 0;
		while (str[i + j] != '\0' && s_str[j] != '\0'
			&& i + j < len && str[i + j] == s_str[j])
			j++;
		if (s_str[j] == '\0')
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}
