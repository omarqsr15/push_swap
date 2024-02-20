/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:01:42 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/02/20 01:50:29 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	do_the_moves(char *inputs, t_stack **heada, t_stack **headb)
{
	if (ft_strncmp("pa\n", inputs) == 0)
		ft_pa(heada, headb);
	else if (ft_strncmp("pb\n", inputs) == 0)
		ft_pb(headb, heada);
	else if (ft_strncmp("ra\n", inputs) == 0)
		ft_ra(heada, 0);
	else if (ft_strncmp("rb\n", inputs) == 0)
		ft_rb(headb, 0);
	else if (ft_strncmp("rr\n", inputs) == 0)
		ft_rr(heada, headb);
	else if (ft_strncmp("rra\n", inputs) == 0)
		ft_rra(heada, 0);
	else if (ft_strncmp("rrb\n", inputs) == 0)
		ft_rrb(headb, 0);
	else if (ft_strncmp("rrr\n", inputs) == 0)
		ft_rrr(heada, headb);
	else if (ft_strncmp("sa\n", inputs) == 0)
		ft_sa(heada, 0);
	else if (ft_strncmp("sb\n", inputs) == 0)
		ft_sb(headb, 0);
	else if (ft_strncmp("ss\n", inputs) == 0)
		ft_ss(heada, headb);
	else
		ft_error();
}

int	main(int ac, char **av)
{
	t_stack	*heada;
	t_stack	*headb;
	char	*inputs;

	heada = ft_parsing(ac, av, heada);
	headb = NULL;
	while (1)
	{
		inputs = get_next_line(0);
		if(inputs == NULL)
			break;
		do_the_moves(inputs, &heada, &headb);
		free(inputs);
	}
	return (0);
}
