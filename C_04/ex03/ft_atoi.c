/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyun2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:10:46 by taehyun2          #+#    #+#             */
/*   Updated: 2023/09/06 17:12:23 by taehyun2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_space(char c)
{
	if (c >= 9 && c <= 13)
		return (1);
	else if (c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	index;
	int	minus;
	int	result;

	index = 0;
	minus = 1;
	result = 0;
	while (is_space(str[index]))
		index++;
	while (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			minus *= -1;
		index++;
	}
	while (str[index] != '\0' && is_num(str[index]))
	{
		result *= 10;
		result += str[index] - '0';
		index++;
	}
	return (result * minus);
}
