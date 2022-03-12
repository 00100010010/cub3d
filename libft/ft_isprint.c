/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jtrebes@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 15:24:16 by jim               #+#    #+#             */
/*   Updated: 2020/05/02 10:15:52 by jtrebes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
