/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_push_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:43:29 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/02/20 16:16:13 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_pa(t_stack **heada, t_stack **headb)
{
	t_stack	*tmp;

	if (*headb == NULL)
		return ;
	tmp = *heada;
	*heada = *headb;
	*headb = (*headb)-> next;
	(*heada)-> next = tmp;
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
}
