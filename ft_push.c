/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:27:15 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/02/06 10:24:40 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_duplicated(t_stack *head, int new_nbr)
{
	while (head)
	{
		if (head->content == new_nbr)
			return (0);
		head = head->next;
	}
	return (1);
}

void	ft_push(t_stack **head, long content)
{
	t_stack	*new_node;

	if (ft_is_duplicated(*head, content))
	{
		new_node = ft_lstnew(content);
		if (!new_node)
			return ;
		ft_lstadd_back(head, new_node);
	}
	else
		ft_error();
}

void	free_stack(t_stack *head)
{
	t_stack	*temp;

	while (head)
	{
		temp = head->next;
		free (temp);
	}
}
