/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_pattern.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 15:02:47 by irhett            #+#    #+#             */
/*   Updated: 2018/06/05 15:07:09 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_wordlen_pattern(char *s, int (*f)(int))
{
	unsigned int	len;
	unsigned int	i;

	len = 0;
	i = 0;
	if (s)
	{
		while (f(s[i]))
			i++;
		while (!f(s[i]))
		{
			if (s[i] == '\0')
				return (len);
			i++;
			len++;
		}
	}
	return (len);
}

static unsigned int		ft_numwords_pattern(char *str, int (*f)(int))
{
	unsigned int	num;
	unsigned int	i;

	num = 0;
	i = 0;
	while (str && str[i] != '\0')
	{
		if (!f(str[i]) && ((f(str[i + 1])) || (str[i + 1] == '\0')))
			num++;
		i++;
	}
	return (num);
}

static char				**sub_split(int (*f)(int), char *tmp, unsigned int num)
{
	unsigned int	x;
	unsigned int	y;
	char			**ans;

	if (!(ans = (char **)malloc(sizeof(char*) * (num + 1))))
		return (NULL);
	x = 0;
	while (x < num)
	{
		y = 0;
		ans[x] = (char*)malloc(sizeof(char) * (ft_wordlen_pattern(tmp, f) + 1));
		if (!ans[x])
			return (NULL);
		while (f(*tmp))
			tmp++;
		while ((!f(*tmp)) && (*tmp != '\0'))
			ans[x][y++] = *(tmp++);
		ans[x++][y] = '\0';
	}
	ans[x] = NULL;
	return (ans);
}

char					**ft_strsplit_pattern(char const *s, int (*f)(int))
{
	char			*tmp;
	unsigned int	num;

	if (!s)
		return (NULL);
	tmp = *((char**)&s);
	num = ft_numwords_pattern(tmp, f);
	return (sub_split(f, tmp, num));
}
