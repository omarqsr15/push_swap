/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   My_tools_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:54:54 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/02/29 01:30:11 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	while (*str >= '0' && *str <= '9')
	{
		if ((re > INT_MAX && sg == 1) || (-re < INT_MIN && sg == -1))
			ft_error();
		re = re * 10 + *str - '0';
		str++;
	}
	return (re * sg);
}

t_stack	*find_max_2(t_stack *head)
{
	t_stack	*max1;
	t_stack	*max2;
	t_stack	*current;

	if (!head && head->index != 0)
		return (NULL);
	max1 = find_max(head);
	max2 = NULL;
	current = head;
	while (current)
	{
		if (current != max1 && (max2 == NULL
				|| current->content > max2->content))
			max2 = current;
		current = current->next;
	}
	return (max2);
}
