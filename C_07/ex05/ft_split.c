/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyun2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:50:00 by taehyun2          #+#    #+#             */
/*   Updated: 2023/09/14 11:54:16 by taehyun2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	is_charset(char c, char *charset)
{
	while (*charset != '\0')
	{
		if (*charset == c)
			return (1);
		charset++;
	}
	return (0);
}

int	cnt_words(char *str, char *charset)
{
	int	cnt;
	int	idx;

	idx = 0;
	cnt = 0;
	while (str[idx] != '\0')
	{
		if (is_charset(str[idx], charset))
		{
			cnt++;
			while (is_charset(str[idx], charset) && str[idx + 1] != '\0')
				idx++;
		}
		idx++;
	}
	if (!is_charset(str[idx - 1], charset))
		cnt++;
	return (cnt);
}

char	*make_word(char *str, char *charset)
{
	char	*word;
	int		idx;

	idx = 0;
	while (str[idx] != '\0' && !is_charset(str[idx], charset))
		idx++;
	word = (char *)malloc(sizeof(char) * (idx + 1));
	idx = 0;
	while (str[idx] != '\0' && !is_charset(str[idx], charset))
	{
		word[idx] = str[idx];
		idx++;
	}
	word[idx] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		word_cnt;
	int		i;

	i = 0;
	word_cnt = cnt_words(str, charset);
	res = (char **)malloc(sizeof(char *) * (word_cnt + 1));
	while (*str)
	{
		while (*str && is_charset(*str, charset))
			str++;
		if (*str && !is_charset(*str, charset))
		{
			res[i++] = make_word(str, charset);
			while (*str && !is_charset(*str, charset))
				str++;
		}
	}
	res[i] = 0;
	return (res);
}
