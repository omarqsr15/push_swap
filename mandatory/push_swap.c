/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:50:07 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/02/25 08:12:13 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_is_sorted(t_stack *heada)
{
	while (heada->next)
	{
		if (heada->content > heada->next->content)
			return (0);
		heada = heada->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*heada;
	t_stack	*headb;

	if (ac < 2)
		return (0);
	heada = NULL;
	headb = NULL;
	heada = ft_parsing(ac, av, heada);
	if (check_is_sorted(heada) == 1)
		exit(EXIT_SUCCESS);
	if (ft_lstsize(heada) == 2)
	{
		ft_sa(&heada, 1);
		ft_lstclear(&heada);
		return (0);
	}
	index_stack(heada);
	if (ft_lstsize(heada) <= 5)
		ft_sort_5(&heada, &headb);
	else
		ft_sort_big(&heada, &headb);
	ft_lstclear(&heada);
	return (0);
}
