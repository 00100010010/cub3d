/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jtrebes@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 16:30:10 by jim               #+#    #+#             */
/*   Updated: 2020/05/02 10:48:52 by jtrebes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlen(register const char *str)
{
	size_t	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}
