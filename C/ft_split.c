/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:14:51 by hbretagn          #+#    #+#             */
/*   Updated: 2025/07/23 14:14:58 by hbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	count;
	int	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (str[i])
	{
		if (!is_sep(str[i], charset) && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (is_sep(str[i], charset))
			in_word = 0;
		i++;
	}
	return (count);
}

char	*malloc_word(char *str, char *charset)
{
	int		i;
	char	*word;

	i = 0;
	while (str[i] && !is_sep(str[i], charset))
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (str[i] && !is_sep(str[i], charset))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		i;

	i = 0;
	split = (char **)malloc(sizeof(char *) * (count_words(str, charset) + 1));
	if (!split)
		return (NULL);
	while (*str)
	{
		while (*str && is_sep(*str, charset))
			str++;
		if (*str)
		{
			split[i] = malloc_word(str, charset);
			if (!split[i])
				return (NULL);
			i++;
			while (*str && !is_sep(*str, charset))
				str++;
		}
	}
	split[i] = NULL;
	return (split);
}

// int	main(void)
// {
// 	char	**tab;
// 	int		i;

// 	tab = ft_split("Salut,comment;,ça:va-bien", ",;:-");
// 	i = 0;
// 	while (tab[i])
// 	{
// 		__builtin_printf("mot[%d] = %s\n", i, tab[i]);
// 		free(tab[i]);
// 		i++;
// 	}
// 	free(tab);
// 	return (0);
// }
