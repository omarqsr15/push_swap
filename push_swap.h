/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:17:37 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/02/18 19:40:16 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				content;
	int				index;
	int				position;
	struct s_stack	*next;
}	t_stack;

typedef struct s_chunk
{
	int	chunk;
	int	min;
	int	max;
}	t_chunk;

// parsing functions
t_stack	*ft_parsing(int ac, char **av, t_stack	*head);
char	**ft_split(char const *str, char d);
long	ft_atoi(char *str);
// error function
void	ft_error(void);
// linked list functions
t_stack	*ft_lstnew(int content);
void	ft_lstadd_back(t_stack **lst, t_stack *newx);
t_stack	*ft_lstlast(t_stack *lst);
int		ft_lstsize(t_stack *lst);
void	ft_lstadd_front(t_stack **head, t_stack *new_node);
// push functions
void	ft_push(t_stack **head, long content);
//moves functions
void	ft_sa(t_stack **heada, int pass);
void	ft_sb(t_stack **headb, int pass);
void	ft_ss(t_stack **heada, t_stack **headb);
void	ft_pa(t_stack **heada, t_stack **headb);
void	ft_pb(t_stack **headb, t_stack **heada);
void	ft_ra(t_stack **heada, int pass);
void	ft_rb(t_stack **headb, int pass);
void	ft_rr(t_stack **heada, t_stack **headb);
void	ft_rra(t_stack **heada, int pass);
void	ft_rrb(t_stack **headb, int pass);
void	ft_rrr(t_stack **heada, t_stack **headb);
// indexing stack functions
void	index_stack(t_stack *head);
t_stack	*find_max(t_stack *head);
t_stack	*find_max_500(t_stack *head);
t_stack	*find_max_2_500(t_stack *head);
int		find_pos_min(t_stack *head);
void	position_stack(t_stack **head);
int		check_index(t_stack *heada, int min, int max);
int		to_top_count(t_stack *headb, t_stack *max);
// swap function
void	ft_sort_3(t_stack **head);
void	ft_sort_5(t_stack **heada, t_stack **headb);
void	ft_sort_100(t_stack **heada, t_stack **headb);
void	ft_sort_500(t_stack **heada, t_stack **headb);
// push b to a functions
void	ft_push_to_a(t_stack **heada, t_stack **headb);

void	*is_free(char **out);
void	ft_lstclear(t_stack **lst);

#endif
