/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyun2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:42:20 by taehyun2          #+#    #+#             */
/*   Updated: 2023/09/14 18:51:45 by taehyun2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	long long	len;
	int			*arr;
	int			i;

	if (min >= max)
		return (NULL);
	i = 0;
	len = max - min;
	arr = (int *)malloc(sizeof(int) * len + 1);
	while (i < len)
	{
		arr[i] = min + i;
		i++;
	}
	return (arr);
}
