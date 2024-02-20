/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   My_tools_0_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:54:54 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/02/20 02:02:59 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	check_index(t_stack *heada, int min, int max)
{
	if ((heada)->index >= min && (heada)->index < max)
		return (1);
	return (0);
}

long	ft_atoi(char *str)
{
	long	re;
	int		sg;

	sg = 1;
	re = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sg *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9' && re < (long)INT_MAX + 1)
	{
		re = re * 10 + *str - '0';
		str++;
	}
	return (re * sg);
}
void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}
int	ft_strncmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
