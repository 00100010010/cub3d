/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jtrebes@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 07:33:26 by jim               #+#    #+#             */
/*   Updated: 2020/05/02 10:15:17 by jtrebes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
