/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 16:07:03 by jim               #+#    #+#             */
/*   Updated: 2020/11/04 16:39:12 by jtrebes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		*ft_bzero_ptr(void *b, size_t len)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)b;
	while (len-- > 0)
		*tmp++ = 0;
	return ((void *)b);
}
