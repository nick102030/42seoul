/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyun2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:47:42 by taehyun2          #+#    #+#             */
/*   Updated: 2023/09/05 16:17:50 by taehyun2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int num)
{
	if (num == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		num = 147483648;
	}
	if (num < 0)
	{
		ft_putchar('-');
		num *= -1;
	}
	if (num < 10)
	{
		ft_putchar(num + '0');
		return ;
	}
	else
		ft_putnbr(num / 10);
	ft_putnbr (num % 10);
}
/*
int	main(void)
{
	ft_putnbr(-2147483648);
}
*/
