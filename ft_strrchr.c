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

char	*ft_strrchr(char *str, int search_char)
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
