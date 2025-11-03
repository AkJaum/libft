/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjaum <akjaum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by jneris-d          #+#    #+#             */
/*   Updated: 2025/11/03 14:57:33 by akjaum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		while(str[i + j] != '\0' && (i + j) < len 
			&& str[i + j] == s_str[j])
		{
			if (s_str[j] == '\0')
				return ((char *)str + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
