/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 19:41:55 by irhett            #+#    #+#             */
/*   Updated: 2018/05/16 19:57:18 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *d, const void *s, int c, size_t n)
{
	char	*temp;

	temp = (char*)d;
//	if (d && s)
//	{
		while (n-- > 0)
		{
			*temp = *((char*)s);
			temp++;
			if (*((char*)(++s) - 1) == c)
				return ((void*)temp);
		}
//	}
	return (NULL);
}
