/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_100.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:59:56 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/02/15 19:29:25 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_index(t_stack *heada, int min, int max)
{
	if ((heada)->index >= min && (heada)->index < max)
		return (1);
	return (0);
}

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

int	nbr_mv(t_stack *headb, t_stack *max)
{
	int		i;
	int		pos;

	i = 0;
	pos = max->position;
	if (pos >= ft_lstsize(headb) / 2)
	{
		while (headb->content != max->content)
		{
			ft_rrb(&headb, 1);
			i++;
		}
	}
	else
	{
		while (headb->content != max->content)
		{
			ft_rb(&headb, 1);
			i++;
		}
	}
	return (i);
}

void	push_max(t_stack **heada, t_stack **headb, t_stack *max)
{
	int	pos;

	pos = max->position;
	if (pos >= ft_lstsize(*headb) / 2)
	{
		while ((*headb)->content != max->content)
			ft_rrb(headb, 1);
	}
	else
	{
		while ((*headb)->content != max->content)
			ft_rb(headb, 1);
	}
	ft_pa(heada, headb);
}

void	ft_push_to_a(t_stack **heada, t_stack **headb)
{
	int	max_1;
	int	max_2;
	t_stack	*node_1;
	t_stack	*node_2;

	// printf("A %d \n", ft_lstsize(*headb));
	while (ft_lstsize(*headb) > 0)
	{
		node_1 = find_max(*headb);
		node_2 = find_max_2(*headb);
		max_1 = nbr_mv(*headb, node_1);
		max_2 = nbr_mv(*headb, node_2);
		if (max_1 <= max_2)
			push_max(heada, headb, node_1);
		else
			push_max(heada, headb, node_2);
	}
}

void	ft_sort_100(t_stack **heada, t_stack **headb)
{
	t_chunk chunks;
	int	cnst;

	index_stack(*heada);
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
	ft_push_to_a(heada, headb);
	index_stack_b(headb);
}
