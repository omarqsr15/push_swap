/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_500.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:59:56 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/02/19 16:20:29 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_to_b_500(t_stack **heada, t_stack **headb, t_chunk *chunks)
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
				if (*heada != NULL && check_index(*heada, chunks->min, chunks->max) == 0)
					ft_rr(heada, headb);
				else
					ft_rb(headb, 1);
			}
			else
				ft_pb(headb, heada);
		}
		else
			ft_ra(heada, 1);
	}
}

void	ft_push_max_500(t_stack **heada, t_stack **headb, t_stack *node)
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

int	to_top_count_500(t_stack *headb, t_stack *max)
{
	int	i;
	int	j;
	int	x;

	i = ft_lstsize(headb);
	j = max->position;
	if (j <= i / 2)
		x = j;
	else
		x = i - j - 1;
	return (x);
}

void	ft_push_a_500(t_stack **heada, t_stack **headb)
{
	t_stack	*max_node1;
	t_stack	*max_node2;

	max_node1 = NULL;
	max_node2 = NULL;
	while (*headb)
	{
		max_node1 = find_max_500(*headb);
		max_node2 = find_max_2_500(*headb);
		if (to_top_count(*headb, max_node1) <= to_top_count(*headb, max_node2))
		{
			ft_push_max_500(heada, headb, max_node1);
			ft_push_max_500(heada, headb, max_node2);
		}
		else
		{
			ft_push_max_500(heada, headb, max_node2);
			ft_push_max_500(heada, headb, max_node1);
			ft_sa(heada, 1);
		}
	}
}

void	ft_sort_500(t_stack **heada, t_stack **headb)
{
	t_chunk	chunks;
	int		cnst;

	index_stack(*heada);
	chunks.chunk = ft_lstsize(*heada) / 9;
	cnst = chunks.chunk;
	chunks.min = 0;
	chunks.max = cnst;
	while (*heada != 0)
	{
		ft_push_to_b_500(heada, headb, &chunks);
		chunks.chunk += cnst;
		chunks.max += cnst;
		chunks.min = chunks.max - cnst;
	}
	position_stack(headb);
	ft_push_a_500(heada, headb);
}
