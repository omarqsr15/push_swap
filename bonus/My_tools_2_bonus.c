/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   My_tools_2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:04:33 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/02/20 20:12:35 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	check_n_2(t_stack **heada, t_stack **headb)
{
	if (check_is_sorted(*heada) && ft_lstsize(*headb) == 0)
		write (1, "OK\n", 3);
	else
	{
		ft_lstclear(headb);
		write (1, "KO\n", 3);
	}
	ft_lstclear(heada);
}

int	check_is_sorted(t_stack *heada)
{
	if (!heada)
		return (0);
	while (heada->next)
	{
		if (heada->content > heada->next->content)
			return (0);
		heada = heada->next;
	}
	return (1);
}

void	ft_lstclear(t_stack **lst)
{
	t_stack	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free (*lst);
		*lst = tmp;
	}
	free(*lst);
	*lst = NULL;
}
