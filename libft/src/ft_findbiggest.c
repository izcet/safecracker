/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findbiggest.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 15:38:37 by irhett            #+#    #+#             */
/*   Updated: 2018/05/28 15:34:13 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_findbiggest(int *arr, unsigned int arr_len)
{
    int				biggest;
    unsigned int	index;

    index = 0;
    biggest = arr[0];
    while (++index < arr_len)
        if (arr[index] > biggest)
            biggest = arr[index];
    return (biggest);
}
