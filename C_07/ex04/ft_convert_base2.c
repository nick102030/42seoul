/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyun2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:01:23 by taehyun2          #+#    #+#             */
/*   Updated: 2023/09/13 16:42:25 by taehyun2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *c)
{
	int	len;

	len = 0;
	while (c[len] != '\0')
		len++;
	return (len);
}

int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int	base_location(char *base, char c)
{
	int	i;
	int	len;

	len = ft_strlen(base);
	i = 0;
	while (i < len)
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	is_valid(char *base)
{
	int	i;
	int	j;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		if (is_space(base[i]) || base[i] == '+' || base[i] == '-')
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

int	ft_atoi_base(char *str, char *base)
{
	int	index;
	int	minus;
	int	result;

	index = 0;
	minus = 1;
	result = 0;
	if (!is_valid(base))
		return (0);
	while (is_space(str[index]))
		index++;
	while (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			minus *= -1;
		index++;
	}
	while (base_location(base, str[index]) != -1)
	{
		result *= ft_strlen(base);
		result += base_location(base, str[index]);
		index++;
	}
	return (result * minus);
}
