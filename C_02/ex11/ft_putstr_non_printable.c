/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyun2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:02:52 by taehyun2          #+#    #+#             */
/*   Updated: 2023/08/31 17:38:44 by taehyun2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int		minus;
	char	*hex;

	hex = "0123456789abcdef";
	while (*str != '\0')
	{
		if (*str <= 31 || *str >= 127)
		{
			write(1, "\\", 1);
			if (*str < 0)
			{
				minus = ((*str) % 256) + 256;
				write(1, &hex[minus / 16], 1);
				write(1, &hex[minus % 16], 1);
			}
			else
			{
				write(1, &hex[*str / 16], 1);
				write(1, &hex[*str % 16], 1);
			}
		}
		else
			write(1, str, 1);
		str++;
	}
}
