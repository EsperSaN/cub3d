/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_no_cut_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 19:54:09 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/13 13:16:15 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"

static size_t	count_on_me(char const *s, char c)
{
	int	word;

	word = 0;
	while (*s)
	{
		if (*s == c)
			word++;
		s++;
	}
	word++;
	return (word);
}

static void	assign_res(char **resplit, char const *s, char c)
{
	size_t	i;
	size_t	big_i;
	int		n;

	i = 0;
	n = 0;
	big_i = 0;
	while (s[i] && i <= ft_strlen(s))
	{
		if (s[i] == c)
		{
			resplit[big_i++] = ft_substr(s, i - n, n + 1);
			n = 0;
		}
		else
			n++;
		i++;
	}
	if (n)
		resplit[big_i++] = ft_substr(s, i - n, n + 1);
	resplit[big_i] = NULL;
}

char	**ft_split_no_cut(char const *s, char c)
{
	char	**resplit;

	if (!s)
		return (NULL);
	resplit = malloc((sizeof(char *)) * (count_on_me(s, c) + 1));
	if (!resplit)
		return (NULL);
	assign_res(resplit, s, c);
	return (resplit);
}
