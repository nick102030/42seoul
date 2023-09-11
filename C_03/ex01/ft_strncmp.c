/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyun2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:08:52 by taehyun2          #+#    #+#             */
/*   Updated: 2023/09/11 18:01:15 by taehyun2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	index;

	index = 0;
	if (n == 0)
		return (0);
	while (s1[index] && s2[index] && index < n)
	{
		if (s1[index] != s2[index])
			break ;
		index++;
	}
	if (index == n)
		return (0);
	return ((unsigned char) s1[index] - (unsigned char) s2[index]);
}
