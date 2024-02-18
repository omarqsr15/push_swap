/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_3_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:54:58 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/02/18 02:50:22 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_stack **head)
{
	int	index;

	index = find_max(*head)->index;
	if (index == (*head)->index)
		ft_ra(head, 1);
	if (index == (*head)->next->index)
		ft_rra(head, 1);
	if ((*head)->content > (*head)->next->content)
		ft_sa(head, 1);
	else
		return ;
}

void	ft_sort_5(t_stack **heada, t_stack **headb)
{
	int	index;

	index = 0;
	while (ft_lstsize(*heada) > 3)
	{
		index = find_pos_min(*heada);
		if (index >= ft_lstsize(*heada) / 2)
		{
			while (index++ < ft_lstsize(*heada))
				ft_rra(heada, 1);
		}
		else
		{
			while (index-- > 0)
				ft_ra(heada, 1);
		}
		ft_pb(headb, heada);
	}
	ft_sort_3(heada);
	ft_pa(heada, headb);
	ft_pa(heada, headb);
	index_stack(*heada);
}
