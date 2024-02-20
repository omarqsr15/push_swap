/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_rrr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:29:25 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/02/20 00:36:39 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_rra(t_stack **heada, int pass)
{
	t_stack	*first;
	t_stack	*last;

	if (*heada == NULL || (*heada)->next == NULL)
		return ;
	first = *heada;
	last = ft_lstlast(*heada);
	while ((*heada)->next != last)
		*heada = (*heada)->next;
	(*heada)->next = NULL;
	last->next = first;
	*heada = last;
	if (pass == 1)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_stack **headb, int pass)
{
	t_stack	*first;
	t_stack	*last;

	if (*headb == NULL || (*headb)->next == NULL)
		return ;
	first = *headb;
	last = ft_lstlast(*headb);
	while ((*headb)->next != last)
		*headb = (*headb)->next;
	(*headb)->next = NULL;
	last->next = first;
	*headb = last;
	if (pass == 1)
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack **heada, t_stack **headb)
{
	ft_rra(heada, 0);
	ft_rrb(headb, 0);
	write(1, "rrr\n", 4);
}
