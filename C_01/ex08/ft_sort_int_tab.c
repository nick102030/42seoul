/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyun2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:01:57 by taehyun2          #+#    #+#             */
/*   Updated: 2023/09/01 15:54:59 by taehyun2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	q_sort(int *arr, int start, int end)
{
	int	pivot;
	int	i;
	int	j;

	pivot = start;
	i = start + 1;
	j = end;
	if (start >= end)
		return ;
	while (i <= j)
	{
		while (i < end && arr[i] <= arr[pivot])
			i++;
		while (j > start && arr[j] >= arr[pivot])
			j--;
		if (i >= j)
			swap(&arr[j], &arr[pivot]);
		else
			swap(&arr[i], &arr[j]);
	}
	q_sort(arr, start, j - 1);
	q_sort(arr, j + 1, end);
}

void	ft_sort_int_tab(int *tab, int size)
{
	q_sort(tab, 0, size - 1);
}
