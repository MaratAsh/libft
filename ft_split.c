/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:50:34 by alcierra          #+#    #+#             */
/*   Updated: 2021/10/10 13:16:27 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_size	ft_size_part(char *s, char c)
{
	t_size	i;

	i = 0;
	while (s[i] != 0 && s[i] != c)
		i++;
	return (i);
}

static int	ft_splited_cnt(char const *s, char c)
{
	int	i;
	int	count;
	int	is_last_c;

	i = 0;
	count = 0;
	is_last_c = 1;
	while (s[i])
	{
		if (s[i] == c)
			is_last_c = 1;
		else
		{
			if (is_last_c == 1)
				count++;
			is_last_c = 0;
		}
		i++;
	}
	return (count);
}

static int	ft_split_free(char **arr_str, t_size word_cnt)
{
	while (word_cnt--)
		free(arr_str[word_cnt]);
	free(arr_str);
	return (0);
}

static int	ft_split_part(char const *s, char c, char **arr_str)
{
	t_size	word_len;
	t_size	dsp;
	t_size	word_cnt;

	dsp = 0;
	word_cnt = 0;
	while (s[dsp] == c && c)
		dsp++;
	while (s[dsp])
	{
		word_len = ft_size_part((char *) s + dsp, c);
		arr_str[word_cnt] = malloc(sizeof(char) * (word_len + 1));
		if (arr_str[word_cnt] == NULL)
			return (ft_split_free(arr_str, word_cnt));
		ft_strlcpy(arr_str[word_cnt], s + dsp, word_len + 1);
		dsp += word_len;
		while (*(s + dsp) == c)
			++dsp;
		++word_cnt;
	}
	arr_str[word_cnt] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**arr_str;

	arr_str = (char **) malloc(sizeof(char *) * (ft_splited_cnt(s, c) + 1));
	if (arr_str == (char **) 0)
		return (NULL);
	if (ft_split_part(s, c, arr_str) == 0)
		return (NULL);
	return (arr_str);
}
