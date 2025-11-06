/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jneris-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:53:50 by jneris-d          #+#    #+#             */
/*   Updated: 2025/11/06 15:53:52 by jneris-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Parece com a strmapi, mas aqui ele passa um ponteiro para a memoria, assim a
//função pode modificar a string sem criar uma nova como na mapi
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
