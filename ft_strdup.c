/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jneris-d <tbpjaum@outlook.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by jneris-d          #+#    #+#             */
/*   Updated: 0000/00/00 00:00:00 by jneris-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
