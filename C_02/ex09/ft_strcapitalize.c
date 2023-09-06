/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyun2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:19:06 by taehyun2          #+#    #+#             */
/*   Updated: 2023/09/06 12:38:28 by taehyun2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_num_alpha(char c)
{
	if (c >= '0' && c <= '9' )
		return (1);
	else if (c >= 'a' && c <= 'z')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int		is_visited;
	char	*tmp;

	tmp = str;
	is_visited = 0;
	while (*str != '\0')
	{
		if (is_num_alpha(*str) == 1)
		{
			if (is_visited == 0 && (*str >= 'a' && *str <= 'z'))
			{
				*str -= 32;
				is_visited = 1;
			}
			else if (is_visited == 1 && (*str >= 'A' && *str <= 'Z'))
				*str += 32;
			else
				is_visited = 1;
		}
		else
			is_visited = 0;
		str++;
	}
	return (tmp);
}
