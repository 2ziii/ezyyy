#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	unsigned int	rank;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*head;
}					t_stack;

int					swap(t_stack *s);
int					swap_a(t_stack *a);
int					swap_b(t_stack *b);
int					swap_ab(t_stack *a, t_stack *b);

int					push(t_stack *push_stack, t_stack *pop_stack);
int					push_a(t_stack *a, t_stack *b);
int					push_b(t_stack *a, t_stack *b);

int					rotate(t_stack *s);
int					rotate_a(t_stack *a);
int					rotate_b(t_stack *b);
int					rotate_ab(t_stack *a, t_stack *b);

int					reverse_rotate(t_stack *s);
int					rev_rotate_a(t_stack *a);
int					rev_rotate_b(t_stack *b);
int					rev_rotate_ab(t_stack *a, t_stack *b);

int					validate_args(int argc, char **argv);
int					check_numeric_values(char **value);
int					check_int_range(char **arr);
unsigned int		parse_args(t_stack *a, int argc, char **argv);
int					insert_node(t_stack *a, char **arr);
unsigned int		check_duplication(t_stack *a);
void				free_node(t_stack *a);
void				get_node_rank(t_stack *a);
int					check_sort(t_stack *a, unsigned int min, unsigned int max);
int					sort_node(t_stack *a, t_stack *b, unsigned int max);
int					radix_sort(t_stack *a, t_stack *b, unsigned int max);

long long			ft_atoi(char *nptr);
void				memory_free(char **res, int idx);
char				**ft_split(char *s, char c);

#endif
