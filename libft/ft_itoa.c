/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jtrebes@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 08:45:19 by jim               #+#    #+#             */
/*   Updated: 2020/05/02 11:11:17 by jtrebes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_int_size(int nbr)
{
	int	size;

	size = 1 + (nbr < 0);
	while (nbr /= 10)
		size++;
	return (size);
}

char		*ft_itoa(int n)
{
	int		i;
	char	*s;
	long	nb;

	nb = n;
	i = ft_int_size(n);
	if (!(s = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	s[i] = '\0';
	if (nb < 0)
	{
		s[0] = '-';
		nb = -nb;
	}
	else
		s[0] = '0';
	while (nb != 0)
	{
		s[--i] = (nb % 10) + '0';
		nb /= 10;
	}
	return (s);
}
