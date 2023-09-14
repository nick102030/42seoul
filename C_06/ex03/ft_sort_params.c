/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyun2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:43:42 by taehyun2          #+#    #+#             */
/*   Updated: 2023/09/13 15:06:03 by taehyun2         ###   ########.fr       */
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

int	ft_strcmp(char *c1, char *c2)
{
	while ((*c1 == *c2) && *c1 != '\0' && *c2 != '\0')
	{
		c1++;
		c2++;
	}
	return ((unsigned char) *c1 - (unsigned char) *c2);
}

void	sort_argv(int argc, char **argv)
{
	int		i;
	int		j;
	char	*tmp;

	i = argc - 1;
	while (i > 1)
	{
		j = 0;
		while (j < i)
		{
			if (ft_strcmp(argv[j], argv[j + 1]) > 0)
			{
				tmp = argv[j];
				argv[j] = argv[j + 1];
				argv[j + 1] = tmp;
			}
			j++;
		}
		i--;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	sort_argv(argc, argv);
	i = 1;
	while (i < argc)
	{
		ft_putchar(argv[i]);
		write(1, "\n", 1);
		i++;
	}
}
