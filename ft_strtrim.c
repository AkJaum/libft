/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akjaum <akjaum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by jneris-d          #+#    #+#             */
/*   Updated: 2025/11/03 14:44:41 by akjaum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static int	ft_char_in_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strtrimmed;
	int	i;
	int	j;

	i = 0;
	j = ft_strlen((char *) s1) - 1;
	while (s1[i] && ft_char_in_set(s1[i], set))
		i++;
	while (j > i && ft_char_in_set(s1[j], set))
		j--;
	strtrimmed = malloc(j - i + 1);
	strtrimmed = ft_substr(s1, i, j - i + 1);
	return (strtrimmed);
}

/*int	main(int argc, char **argv)
{
	if (argc < 3)
		return (0);
	printf("String trimmed: %s", ft_strtrim(argv[1], argv[2]));
}*/
