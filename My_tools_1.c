/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   My_tools_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:54:23 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/02/13 18:13:52 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnew(int content)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->index = -1;
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*tmp;

	tmp = lst;
	if (!tmp)
		return (NULL);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

void	ft_lstadd_back(t_stack **lst, t_stack *newx)
{
	t_stack	*last;

	if (!lst)
		return ;
	if (!*lst)
		*lst = newx;
	else
	{
		last = ft_lstlast(*lst);
		last->next = newx;
	}
}

int	ft_lstsize(t_stack *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}
void	ft_lstadd_front(t_stack **lst, t_stack *newx)
{
	if (!newx || !lst)
		return ;
	newx->next = *lst;
	*lst = newx;
}
