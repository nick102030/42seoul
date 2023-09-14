/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyun2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:55:30 by taehyun2          #+#    #+#             */
/*   Updated: 2023/09/14 12:23:07 by taehyun2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	len;
	int	*arr;
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	len = max - min;
	i = 0;
	arr = (int *)malloc(sizeof(int) * len + 1);
	if (arr == NULL)
	{
		*range = NULL;
		return (-1);
	}
	while (i < len)
	{
		arr[i] = min + i;
		i++;
	}
	*range = arr;
	return (i);
}
