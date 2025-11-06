/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jneris-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:53:56 by jneris-d          #+#    #+#             */
/*   Updated: 2025/11/06 15:53:57 by jneris-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Diferente da strlcat, strjoin cria uma nova string que recebe o valor de
//duas strings concatenadas. Também retorna um pontiero para a nova string
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*stotal;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	stotal = malloc(len);
	if (!stotal)
		return (NULL);
	ft_strlcpy(stotal, (char *)s1, len);
	ft_strlcat(stotal, s2, len);
	return (stotal);
}
