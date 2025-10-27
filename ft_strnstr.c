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

char	*ft_strnstr(const char *str, const char *s_str, size_t len);
{
	size_t	i;
	size_t	j;
	
	i = 0;
	if (!s_str[0])
    		return (str);
	while (str[i] != '\0' && i < len)
	{
		ii = 0;
		while(str[i + j] != '\0' && (i + j) < len 
			&& str[i + j] == s_str[j])
		{
			if (s_str[ii] == '\0')
				return (str + i)
			ii++;
		}
		i++;
	}
	return (NULL);
}
