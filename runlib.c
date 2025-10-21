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

#include <stdio.h> 

int	main(void)
{
	printf("Teste isalpha //A: %d\n", ft_isalpha('A'));
	printf("Teste isalpha //a: %d\n", ft_isalpha('a'));
        printf("Teste isalpha //9: %d\n", ft_isalpha('9'));

	printf("------------------------------------------------------------");

	printf("Teste isdigit //8: %d\n", ft_isdigit('8'));
        printf("Teste isdigit //A: %d\n", ft_isdigit('A'));

	return (0);
}
