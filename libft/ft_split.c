/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihalim <ihalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:33:02 by ihalim            #+#    #+#             */
/*   Updated: 2024/12/06 11:27:59 by ihalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c || s[i] == '\t')
			i++;
		else
		{
			count++;
			while (s[i] && s[i] != c && s[i] != '\t')
				i++;
		}
	}
	return (count);
}

static char	*get_word(char const *s, char c, int *i)
{
	int	start;

	while ((s[*i] == '\t' || s[*i] == c) && s[*i])
		(*i)++;
	start = *i;
	while ((s[*i] != '\t' && s[*i] != c) && s[*i])
		(*i)++;
	return (ft_substr(s, start, *i - start));
}

static void	free_arr(char **arr, int arr_i)
{
	while (arr_i--)
		free(arr[arr_i]);
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		arr_i;
	int		count;
	int		i;

	if (!s)
		return (NULL);
	count = count_words(s, c);
	arr = (char **)malloc(sizeof(char *) * (count + 1));
	if (arr == NULL)
		return (NULL);
	arr_i = 0;
	i = 0;
	while (arr_i < count)
	{
		arr[arr_i] = get_word(s, c, &i);
		if (arr[arr_i] == NULL)
		{
			free_arr(arr, arr_i);
			return (NULL);
		}
		arr_i++;
	}
	arr[arr_i] = NULL;
	return (arr);
}
