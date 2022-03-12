/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrebes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 07:49:49 by jtrebes           #+#    #+#             */
/*   Updated: 2020/05/02 10:57:12 by jtrebes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n-- > 0)
	{
		if ((*(unsigned char *)dst++ = *(unsigned char *)src++)
			== (unsigned char)c)
		{
			return (dst);
		}
	}
	return (0);
}
