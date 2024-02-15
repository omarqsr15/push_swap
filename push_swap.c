/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:50:07 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/02/15 19:05:26 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	test_func(t_stack *heada)
{
	t_stack	*tmp;

	tmp = heada;
	while (tmp)
	{
		printf("->numb %d      ->index %d\n", tmp->content,tmp->index);
		tmp = tmp->next;
	}
	while (heada)
	{
		tmp = heada->next;
		free(heada);
		heada = tmp;
	}
}

int	main(int ac, char **av)
{
	t_stack	*heada;
	t_stack	*headb;

	heada = NULL;
	headb = NULL;
	if (ac <= 2)
		exit(EXIT_SUCCESS);
	heada = ft_parsing(ac, av, heada);
	index_stack(heada);
	index_stack_b(&heada);
	ft_sort_100(&heada, &headb);
	puts("//////////////////");
	test_func(heada);
	puts("//////////////////");
	test_func(headb);
	return (0);
}
