/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-qasr <oel-qasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:30:05 by oel-qasr          #+#    #+#             */
/*   Updated: 2024/02/20 01:27:17 by oel-qasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_stack
{
	int				content;
	int				index;
	int				position;
	struct s_stack	*next;
}	t_stack;

// error function
void	ft_error(void);
// parsing functions
t_stack	*ft_parsing(int ac, char **av, t_stack	*head);
char	**ft_split(char const *str, char d);
long	ft_atoi(char *str);
int		ft_strncmp(const char *s1, const char *s2);
void	ft_putstr(char *s);
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
// linked list functions
t_stack	*ft_lstnew(int content);
void	ft_lstadd_back(t_stack **lst, t_stack *newx);
t_stack	*ft_lstlast(t_stack *lst);
int		ft_lstsize(t_stack *lst);
void	ft_lstadd_front(t_stack **head, t_stack *new_node);
// get next line functions
char	*get_next_line(int fd);
size_t	ft_strlen(char const *str);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(char *str, int c);
// free functions
void	*is_free(char **out);
void	ft_lstclear(t_stack **lst);

#endif
