/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:00:25 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/02/25 08:07:33 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_for_error(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	check_and_push(char **input, t_stack **head)
{
	while (*input)
	{
		if (ft_atoi(*input) > INT_MAX || ft_atoi(*input) < INT_MIN)
			ft_error();
		if (check_for_error(*input) == 0)
			ft_error();
		else
			ft_push(head, ft_atoi(*input));
		input++;
	}
}

t_stack	*ft_parsing(int ac, char **av, t_stack	*head)
{
	int		j;
	char	**str;
	t_stack	*tmp;

	head = NULL;
	tmp = NULL;
	j = 1;
	while (j < ac)
	{
		str = ft_split(av[j], ' ');
		if (!str)
			exit(1);
		if (*str == (void *)0)
			ft_error();
		check_and_push(str, &head);
		j++;
		is_free(str);
	}
	return (head);
}
