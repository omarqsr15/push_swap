/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:38:16 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/02/19 16:05:44 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
