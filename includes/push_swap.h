/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:26:27 by aperol-h          #+#    #+#             */
/*   Updated: 2021/10/16 18:29:35 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>

//	structs
typedef struct s_chunk
{
	int				size;
	int				*s_arr;
	char			col;
	struct s_chunk	*next;
}	t_chunk;

typedef struct s_chunks
{
	int				size;
	struct s_chunk	*list;
}	t_chunks;

typedef struct s_list
{
	int				*arr;
	int				size;
	char			col;
}	t_list;

typedef struct s_stack
{
	t_list			a;
	t_list			b;
	int				*sorted;
	struct s_chunks	chunks;
}	t_stack;

//	minilibft
void			arr_dup(int *dest, int *src, int size);
long			ft_int_atoi(char *s);
void			ft_print_str(char *s);
int				ft_streq(char *s1, char *s2);
void			*ft_pmalloc(size_t size);

//	arg parser
char			*join_args(int argc, char **argv);
int				count_str_arr(char **arr);
void			free_str_arr(char **arr);

//	ps funcs
int				setup_stack(int argc, char **argv, t_stack *stack);
int				ps_exec(t_stack *stack, char *op);
int				check_finished(t_stack *stack);
void			solver_chunk(t_stack *stack, int chunksize);

//	arr utils
int				get_idx_arr(int *arr, int nbr, int size);
void			sort_arr(int *arr, int size);

//	list utils
void			ft_lstclear(t_chunk **lst);
t_chunk			*ft_lstnew(int s, char col);
void			ft_lstadd_front(t_chunks *chunks, t_chunk *new);
void			ft_lsdelfirst(t_chunks *lst);

//	chunk_solver utils
int				get_nbr(t_stack *stack, t_list *col, int idx);
int				get_next_nbr_in_chunk(t_stack *stack,
					t_chunk *chunk, t_list *col);
int				is_top_in_chunk(t_chunk *chunk, int nbr);

void			three_solver(t_stack *stack);
void			four_solver(t_stack *stack);
void			five_solver(t_stack *stack);

//	ft_split
void			*ft_memcpy(void *dest, const void *src, size_t n);
unsigned int	ft_strlcpy(char *dst, const char *src, size_t size);
char			**ft_split(char const *s, char c);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_strlen(const char *s);
#endif