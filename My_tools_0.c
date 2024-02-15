/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   My_tools_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:54:54 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/02/15 18:49:54 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

long	ft_atoi(char *str)
{
	long	re;
	int			sg;

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
t_stack	*find_max_2(t_stack *head)
{
	int max;

	max = find_max(head)->index - 1;
	while (head)
	{
		if (head->index == max)
		{
			return &(*head);
		}
		head = head->next;
	}
	return (head);
}
