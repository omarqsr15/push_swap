/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_ss.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:18:29 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/02/13 18:22:43 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack **heada, int pass)
{
	t_stack	*first;
	t_stack	*second;

	if (*heada == NULL || (*heada)->next == NULL)
		return ;
	first = *heada;
	second = (*heada)->next;
	first->next = second->next;
	second->next = first;
	*heada = second;
	if (pass == 1)
		write(1, "sa\n", 3);
}

void	ft_sb(t_stack **headb, int pass)
{
	t_stack	*first;
	t_stack	*second;

	if (*headb == NULL || (*headb)->next == NULL)
		return ;
	first = *headb;
	second = (*headb)->next;
	first->next = second->next;
	second->next = first;
	*headb = second;
	if (pass == 1)
		write(1, "sb\n", 3);
}

void	ft_ss(t_stack **heada, t_stack **headb)
{
	ft_sa(heada, 0);
	ft_sb(headb, 0);
	write(1, "ss\n", 3);
}
