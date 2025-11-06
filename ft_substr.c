/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jneris-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:55:02 by jneris-d          #+#    #+#             */
/*   Updated: 2025/11/06 15:55:04 by jneris-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Cria uma substring a partir da string original, start é onde começa a copiar
//e para em len
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;

	if (!s)
		return (NULL);
	i = ft_strlen((char *)s);
	if (start >= i)
		return (ft_strdup(""));
	if (len > i - start)
		len = i - start;
	subs = malloc(len + 1);
	if (!subs)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}
