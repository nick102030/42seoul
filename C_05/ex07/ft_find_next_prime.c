/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyun2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:28:59 by taehyun2          #+#    #+#             */
/*   Updated: 2023/09/13 14:53:05 by taehyun2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
{
	long long	index;

	if (nb <= 1)
		return (ft_find_next_prime(nb + 1));
	index = 2;
	while (index * index <= nb)
	{
		if (nb % index == 0)
			return (ft_find_next_prime(nb + 1));
		index++;
	}
	return (nb);
}
