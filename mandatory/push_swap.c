/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:50:07 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/02/19 16:06:16 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
void fin()
{
	system("leaks push_swap");
}

int	main(int ac, char **av)
{
	t_stack	*heada;
	t_stack	*headb;
	heada = NULL;
	headb = NULL;
	heada = ft_parsing(ac, av, heada);
	index_stack(heada);
	if (ft_lstsize(heada) <= 5)
		ft_sort_5(&heada, &headb);
	else if (ft_lstsize(heada) > 5 && ft_lstsize(heada) <= 200)
		ft_sort_100(&heada, &headb);
	else if (ft_lstsize(heada) > 200)
		ft_sort_500(&heada, &headb);
	// atexit(fin);
	ft_lstclear(&heada);
	return (0);
}
