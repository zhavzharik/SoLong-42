/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:15:03 by abridger          #+#    #+#             */
/*   Updated: 2021/10/25 17:51:48 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nb_len(long nb)
{
	size_t	len;

	len = 0;
	if (nb < 0)
	{
		len = 1;
		nb = -nb;
	}
	while (nb >= 10)
	{
		nb /= 10;
		len++;
	}
	len += 1;
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	number;
	size_t	len;

	number = n;
	str = NULL;
	len = ft_nb_len(number);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (number == 0)
		str[0] = '0';
	if (number < 0)
	{
		str[0] = '-';
		number *= -1;
	}
	len -= 1;
	while (number)
	{
		str[len--] = number % 10 + '0';
		number = number / 10;
	}
	return (str);
}
