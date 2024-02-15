/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   My_tools_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:56:27 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/02/15 18:48:17 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_stack(t_stack *head)
{
	t_stack	*current;
	t_stack	*tmp;
	int		count;

	current = head;
	while (current)
	{
		count = 0;
		tmp = head;
		while (tmp)
		{
			if (current->content > tmp->content)
				count++;
			tmp = tmp->next;
		}
		current->index = count;
		current = current->next;
	}
}

int	find_pos_min(t_stack *head)
{
	int		min;
	int		i;
	int		pos;

	pos = 0;
	i = 0;
	min = head->content;
	while (head)
	{
		if (head->content < min)
		{
			min = head->content;
			pos = i;
		}
		i++;
		head = head->next;
	}
	return (pos);
}

t_stack	find_min(t_stack *head)
{
	t_stack	min;

	min = *head;
	while (min.next)
	{
		if (min.index == 0)
			break ;
		min = *min.next;
	}
	return (min);
}

t_stack	*find_max(t_stack *head)
{
	int		max;
	t_stack	*node_max;

	max = head->content;
	node_max = head;
	while (head)
	{
		if (head->content > max)
		{
			max = head->content;
			node_max = head;
		}
		head = head->next;
	}
	return (node_max);
}
void	index_stack_b(t_stack **head)
{
	t_stack	*tmp;
	int	i;

	tmp = *head;
	i = 0;
	while (tmp)
	{
		tmp->position = i;
		i++;
		tmp = tmp->next;
	}
}
