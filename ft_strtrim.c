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
//Checa se o caracter atual de s1 existe dentro de set
static int	ft_charinset(char c, const char *set)
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

//Remove das pontas de uma string o set de caracteres
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strtrimmed;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen((char *) s1) - 1;
	while (s1[i] && ft_charinset(s1[i], set))
		i++;
	while (j > i && ft_charinset(s1[j], set))
		j--;
	strtrimmed = ft_substr(s1, i, j - i + 1);
	return (strtrimmed);
}

/*int	main(int argc, char **argv)
{
	if (argc < 3)
		return (0);
	printf("String trimmed: %s", ft_strtrim(argv[1], argv[2]));
}*/
