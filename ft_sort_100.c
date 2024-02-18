/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_100.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:59:56 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/02/18 17:12:41 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_to_b(t_stack **heada, t_stack **headb, t_chunk *chunks)
{
	int	len;

	len = ft_lstsize(*headb);
	while (*heada != NULL && ft_lstsize(*headb) < chunks->chunk)
	{
		if (check_index(*heada, chunks->min, chunks->max) == 1)
		{
			if ((*heada)->index < (chunks->chunk + len) / 2)
			{
				ft_pb(headb, heada);
				ft_rb(headb, 1);
			}
			else
				ft_pb(headb, heada);
		}
		else
			ft_ra(heada, 1);
	}
}

void	ft_push_max(t_stack **heada, t_stack **headb, t_stack *node)
{
	int	i;

	i = node->position;
	if (i <= ft_lstsize(*headb) / 2)
	{
		while (i-- > 0)
			ft_rb(headb, 1);
	}
	else
	{
		while (i++ < ft_lstsize(*headb))
			ft_rrb(headb, 1);
	}
	ft_pa(heada, headb);
	position_stack(headb);
}

void	ft_push_to_a(t_stack **heada, t_stack **headb)
{
	t_stack	*max_node1;

	max_node1 = NULL;
	max_node1 = find_max(*headb);
	while (*headb)
	{
		max_node1 = find_max(*headb);
		ft_push_max(heada, headb, max_node1);
	}
}

void	ft_sort_100(t_stack **heada, t_stack **headb)
{
	t_chunk	chunks;
	int		cnst;

	index_stack(*heada);
	chunks.chunk = ft_lstsize(*heada) / 5;
	chunks.chunk = ft_lstsize(*heada) / 5;
	cnst = chunks.chunk;
	chunks.min = 0;
	chunks.max = cnst;
	while (*heada != 0)
	{
		ft_push_to_b(heada, headb, &chunks);
		chunks.chunk += cnst;
		chunks.max += cnst;
		chunks.min = chunks.max - cnst;
	}
	position_stack(headb);
	ft_push_to_a(heada, headb);
}
