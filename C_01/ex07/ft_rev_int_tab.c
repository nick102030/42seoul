/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyun2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 19:21:01 by taehyun2          #+#    #+#             */
/*   Updated: 2023/09/01 15:54:49 by taehyun2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = size - 1;
	while (i < size / 2)
	{
		tmp = tab[i];
		tab[i] = tab[j];
		tab[j] = tmp;
		i++;
		j--;
	}
}
