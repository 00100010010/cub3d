/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 16:36:23 by jim               #+#    #+#             */
/*   Updated: 2020/11/02 12:15:42 by jtrebes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			size;
	char			*out;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	size = ft_strlen(s);
	size -= start;
	if (size < len)
		len = size;
	if (!(out = (char *)malloc((len + 1) * sizeof(char))))
		return (0);
	i = 0;
	while (i < len)
	{
		out[i] = s[i + start];
		i++;
	}
	out[i] = '\0';
	return (out);
}
