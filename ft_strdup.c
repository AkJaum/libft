/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jneris-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:53:44 by jneris-d          #+#    #+#             */
/*   Updated: 2025/11/06 15:53:45 by jneris-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Cria uma nova string usando malloc e copia str para a nova string
#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*sdest;
	int		size;
	int		i;

	size = 0;
	i = 0;
	while (str[size] != '\0')
		size++;
	sdest = malloc(size + 1);
	if (!sdest)
		return (NULL);
	while (i < size)
	{
		sdest[i] = str[i];
		i++;
	}
	sdest[i] = '\0';
	return (sdest);
}
