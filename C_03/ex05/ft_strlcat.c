/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyun2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:52:56 by taehyun2          #+#    #+#             */
/*   Updated: 2023/09/07 13:33:55 by taehyun2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_len;
	unsigned int	src_len;

	i = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	while (*dest != '\0')
	{
		dest++;
		i++;
	}
	while (*src && i + 1 < size)
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	*dest = '\0';
	if (dest_len > size)
		return (src_len + size);
	else
		return (src_len + dest_len);
}
/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char c1[30] = "123";
	char c2[] = "456789abcdef";

	char s1[30] = "123";
	char s2[] = "456789abcdef";

	printf("%d\n", ft_strlcat(c1, c2, 1));
	printf("%s\n", c1);

	printf("%d\n", strlcat(s1, s2, 1));
	printf("%s\n", s1);
}*/
