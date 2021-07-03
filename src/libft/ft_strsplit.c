/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 22:00:06 by mderri            #+#    #+#             */
/*   Updated: 2019/10/01 00:57:28 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_words(char const *s, char c)
{
	int v;
	int i;
	int cnt_word;

	i = 0;
	v = 0;
	cnt_word = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && v == 0)
		{
			v = 1;
			cnt_word++;
		}
		else if (s[i] == c && v == 1)
			v = 0;
		i++;
	}
	return (cnt_word);
}

static char		**ft_allocation_ligne_colonne(char **str, char const *s, char c)
{
	int	i;
	int	countcoln;

	i = 0;
	countcoln = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			countcoln++;
			if (s[i + 1] == c || s[i + 1] == '\0')
			{
				*str = (char *)malloc(sizeof(char) * (countcoln + 1));
				str++;
				countcoln = 0;
			}
		}
		i++;
	}
	return (str);
}

static char		**ft_remplissage_tab(char **str, char const *s, char c)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			str[k][j] = s[i];
			j++;
			if (s[i + 1] == c || s[i + 1] == '\0')
			{
				str[k][j] = '\0';
				k++;
				j = 0;
			}
		}
		i++;
	}
	str[k] = 0;
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		j;

	if (!s)
		return (NULL);
	j = ft_count_words(s, c);
	if (!(str = (char **)malloc(sizeof(char *) * (j + 1))))
		return (NULL);
	str = ft_allocation_ligne_colonne(str, s, c);
	str -= j;
	str = ft_remplissage_tab(str, s, c);
	return (str);
}
