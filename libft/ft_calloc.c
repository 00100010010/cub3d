/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jtrebes@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 11:50:30 by jim               #+#    #+#             */
/*   Updated: 2020/05/01 14:59:03 by jtrebes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*dst;
	size_t	total;

	total = size * count;
	if (!(dst = malloc(total)))
		return (0);
	ft_bzero(dst, total);
	return (dst);
}
