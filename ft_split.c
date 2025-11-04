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

int	ft_countwords(char const *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
			n++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (n);
}

void	ft_dosplit(char **strarray, char const *s, unsigned int i, char c)
{
	unsigned int	start;
	unsigned int	j;

	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != '\0' && s[i] != c)
		{
			start = i;
			while (s[i] != c && s[i] != '\0')
				i++;
			strarray[j] = ft_substr(s, start, i - start);
			j++;
		}
	}
	strarray[j] = NULL;
}

char	**ft_split(char const *s, char c)
{
	unsigned int	i;
	int				nwords;
	char			**strarray;

	if (!s)
		return (NULL);
	i = 0;
	nwords = ft_countwords(s, c);
	strarray = malloc((nwords + 1) * sizeof(char *));
	if (!strarray)
		return (NULL);
	ft_dosplit(strarray, s, i, c);
	return (strarray);
}
