/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:05:33 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/02/18 19:36:32 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	ft_words(const char *str, char d)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (i == 0 && str[i] != d)
			count++;
		if (str[i] == d && str[i + 1] != d && str[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}

static	int	split_strlen(const char *str, char d)
{
	int	i;

	i = 0;
	while (str[i] != d && str[i])
		i++;
	return (i);
}

void	*is_free(char **out)
{
	size_t	i;

	i = 0;
	while (out[i])
	{
		free(out[i]);
		i++;
	}
	free(out);
	return (NULL);
}

static	void	alloc_str(const char **str, char **out, char d)
{
	int	i;
	int	len;

	i = 0;
	len = split_strlen(*str, d);
	*out = (char *)malloc(len + 1);
	if (!*out)
		return ;
	while (i < len)
	{
		(*out)[i] = **str;
		i++;
		(*str)++;
	}
	(*out)[i] = '\0';
}

char	**ft_split(char const *str, char d)
{
	char	**out;
	int		wc;
	int		i;

	if (!str)
		return (NULL);
	wc = ft_words(str, d);
	i = 0;
	out = (char **)malloc((wc + 1) * sizeof(char *));
	if (!out)
		return (NULL);
	while (i < wc)
	{
		while (*str == d)
			str++;
		alloc_str(&str, &out[i], d);
		if (!out[i])
			return (is_free(out));
		i++;
	}
	out[i] = 0;
	return (out);
}
