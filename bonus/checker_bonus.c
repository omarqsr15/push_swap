/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:01:42 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/02/21 20:09:06 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	do_the_moves(char *inputs, t_stack **heada, t_stack **headb)
{
	if (ft_strncmp("pa", inputs) == 0)
		ft_pa(heada, headb);
	else if (ft_strncmp("pb", inputs) == 0)
		ft_pb(headb, heada);
	else if (ft_strncmp("ra", inputs) == 0)
		ft_ra(heada, 0);
	else if (ft_strncmp("rb", inputs) == 0)
		ft_rb(headb, 0);
	else if (ft_strncmp("rr", inputs) == 0)
		ft_rr(heada, headb);
	else if (ft_strncmp("rra", inputs) == 0)
		ft_rra(heada, 0);
	else if (ft_strncmp("rrb", inputs) == 0)
		ft_rrb(headb, 0);
	else if (ft_strncmp("rrr", inputs) == 0)
		ft_rrr(heada, headb);
	else if (ft_strncmp("sa", inputs) == 0)
		ft_sa(heada, 0);
	else if (ft_strncmp("sb", inputs) == 0)
		ft_sb(headb, 0);
	else if (ft_strncmp("ss", inputs) == 0)
		ft_ss(heada, headb);
	else
		ft_error();
}

int	check_input(char *inputs)
{
	if (ft_strncmp("pa\n", inputs) == 0)
		return (1);
	else if (ft_strncmp("pb\n", inputs) == 0)
		return (1);
	else if (ft_strncmp("ra\n", inputs) == 0)
		return (1);
	else if (ft_strncmp("rb\n", inputs) == 0)
		return (1);
	else if (ft_strncmp("rr\n", inputs) == 0)
		return (1);
	else if (ft_strncmp("rra\n", inputs) == 0)
		return (1);
	else if (ft_strncmp("rrb\n", inputs) == 0)
		return (1);
	else if (ft_strncmp("rrr\n", inputs) == 0)
		return (1);
	else if (ft_strncmp("sa\n", inputs) == 0)
		return (1);
	else if (ft_strncmp("sb\n", inputs) == 0)
		return (1);
	else if (ft_strncmp("ss\n", inputs) == 0)
		return (1);
	return (0);
}

void	while_(char **str)
{
	char	*inputs;
	char	*s1;

	while (1)
	{
		inputs = get_next_line(0);
		if (inputs == NULL)
			break ;
		if (!check_input(inputs))
		{
			free(*str);
			ft_error();
		}
		s1 = *str;
		*str = ft_strjoin(*str, inputs);
		free(s1);
		free(inputs);
	}
}

int	check_1(char **instr, t_stack *heada)
{
	if (!instr && !check_is_sorted(heada))
	{
		write (1, "KO\n", 3);
		return (1);
	}
	if (!instr && check_is_sorted(heada))
	{
		write (1, "OK\n", 3);
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*heada;
	t_stack	*headb;
	char	*str;
	char	**instr;
	int		i;

	if (ac == 1)
		exit(EXIT_SUCCESS);
	heada = NULL;
	heada = ft_parsing(ac, av, heada);
	headb = NULL;
	str = ft_strdup("");
	while_(&str);
	instr = ft_split(str, '\n');
	if (check_1(instr, heada))
		return (0);
	free (str);
	i = 0;
	while (instr[i])
		do_the_moves(instr[i++], &heada, &headb);
	is_free(instr);
	check_n_2(&heada, &headb);
	return (0);
}
