/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyun2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:40:45 by taehyun2          #+#    #+#             */
/*   Updated: 2023/09/14 18:49:24 by taehyun2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char *c)
{
	while (*c != '\0')
	{
		write(1, c, 1);
		c++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		ft_putchar(argv[0]);
	write(1, "\n", 1);
}
