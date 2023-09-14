/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyun2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:01:16 by taehyun2          #+#    #+#             */
/*   Updated: 2023/09/14 12:01:44 by taehyun2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *c);
int		is_space(char c);
int		is_valid(char *base);
int		base_location(char *base, char c);
int		ft_atoi_base(char *str, char *base);
char	*g_conv_char;
int		g_idx;

int	nbr_len(long long nbr, int base_len)
{
	int	len;

	if (!nbr)
		return (1);
	while (nbr)
	{
		nbr /= base_len;
		len++;
	}
	return (len);
}

void	make_arr(int n, char *base, int base_len)
{
	if (n >= base_len)
		make_arr(n / base_len, base, base_len);
	g_conv_char[g_idx++] = base[n % base_len];
}

void	putnbr_base(int num, char *base)
{
	int	base_len;

	g_idx = 0;
	base_len = ft_strlen(base);
	if (!is_valid(base))
		return ;
	if (num == -2147483648)
	{
		g_conv_char[g_idx++] = '-';
		make_arr(2147483648 / base_len, base, base_len);
		return ;
	}
	if (num < 0)
	{
		g_conv_char[g_idx++] = '-';
		num *= -1;
	}
	make_arr(num, base, base_len);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long	num;
	int			size;

	num = ft_atoi_base(nbr, base_from);
	size = nbr_len(num, ft_strlen(base_to));
	g_conv_char = (char *)malloc(sizeof(char) * (size + 1));
	g_conv_char[size] = 0;
	if (!is_valid(base_from) || !is_valid(base_to))
		return (NULL);
	putnbr_base(num, base_to);
	return (g_conv_char);
}
