/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_rr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:20:38 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/02/18 02:56:55 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack **heada, int pass)
{
	t_stack	*first;
	t_stack	*last;

	if (*heada == NULL || (*heada)->next == NULL)
		return ;
	first = *heada;
	last = ft_lstlast(*heada);
	*heada = first -> next;
	last->next = first;
	first->next = NULL;
	if (pass == 1)
		write(1, "ra\n", 3);
}

void	ft_rb(t_stack **headb, int pass)
{
	t_stack	*first;
	t_stack	*last;

	if (*headb == NULL || (*headb)->next == NULL)
		return ;
	first = *headb;
	last = ft_lstlast(*headb);
	*headb = first -> next;
	last->next = first;
	first->next = NULL;
	if (pass == 1)
		write(1, "rb\n", 3);
}

void	ft_rr(t_stack **heada, t_stack **headb)
{
	ft_ra(heada, 0);
	ft_rb(headb, 0);
	write(1, "rr\n", 3);
}
