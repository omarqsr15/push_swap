/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:27:15 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/02/20 02:02:48 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_is_duplicated(t_stack *head, int new_nbr)
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
