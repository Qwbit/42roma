/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldoni <dbaldoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 23:49:27 by dbaldoni          #+#    #+#             */
/*   Updated: 2023/02/10 09:05:07 by dbaldoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(char const *s, char c)
{
	size_t	flag;
	size_t	word;
	int		i;

	i = 0;
	flag = 0;
	word = 0;
	while (s[i])
	{
		while (s[i] != c && s[i])
		{
			flag = 1;
			i++;
		}
		word = word + flag;
		flag = 0;
		if (!s[i])
			break ;
		i++;
	}
	return (word);
}

typedef struct s_var
{
	int	i;
	int	word;
	int	len;
}	t_var;

char	**ft_split(char const *s, char c)
{
	char	**split;
	t_var	var;

	if (!s)
		return (NULL);
	var.i = 0;
	var.word = ft_word_count(s, c);
	split = malloc ((var.word + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	split[var.word] = NULL;
	while (*s)
	{
		if (*s != c)
		{
			var.len = 0;
			while (*s && *s != c && ++var.len)
				++s;
			split[var.i++] = ft_substr(s - var.len, 0, var.len);
		}
		else
			++s;
	}	
	return (split);
}
