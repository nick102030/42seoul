/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyun2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:39:54 by taehyun2          #+#    #+#             */
/*   Updated: 2023/09/12 14:31:14 by taehyun2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *c)
{
	int	len;

	len = 0;
	while (c[len] != '\0')
		len++;
	return (len);
}

int	is_valid(char *base)
{
	unsigned int	i;
	unsigned int	j;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	len;

	if (!is_valid(base))
		return ;
	len = ft_strlen(base);
	if (nbr == -2147483648)
	{
		write(1, "-", 1);
		ft_putnbr_base(2147483648 / len, base);
		ft_putnbr_base(2147483648 % len, base);
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr < len)
	{
		write(1, &base[nbr], 1);
		return ;
	}
	else
		ft_putnbr_base(nbr / len, base);
	ft_putnbr_base(nbr % len, base);
}
