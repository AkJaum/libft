/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jneris-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:54:50 by jneris-d          #+#    #+#             */
/*   Updated: 2025/11/06 15:54:51 by jneris-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int search_char)
{
	char	*last;
	int		i;

	i = 0;
	last = NULL;
	while (str[i] != '\0')
	{
		if (str[i] == (char)search_char)
			last = (char *) str + i;
		i++;
	}
	if ((char)search_char == '\0')
		return ((char *) str + i);
	return (last);
}
