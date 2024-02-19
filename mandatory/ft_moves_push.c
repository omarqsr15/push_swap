/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:43:29 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/02/17 17:19:54 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stack **heada, t_stack **headb)
{
	t_stack	*tmp;

	if (*headb == NULL)
		return ;
	tmp = *heada;
	*heada = *headb;
	*headb = (*headb)-> next;
	(*heada)-> next = tmp;
	write(1, "pa\n", 3);
}

void	ft_pb(t_stack **headb, t_stack **heada)
{
	t_stack	*tmp;

	if (*heada == NULL)
		return ;
	tmp = *headb;
	*headb = *heada;
	*heada = (*heada)-> next;
	(*headb)-> next = tmp;
	write(1, "pb\n", 3);
}
