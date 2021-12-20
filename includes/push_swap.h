/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satori <satori@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 01:24:41 by mrojas-e          #+#    #+#             */
/*   Updated: 2021/12/20 15:50:36 by satori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//====INCLUDES====//

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "../libft/libft.h"
# include <stdbool.h>

//====DEFINES====//

# define ERROR -1

//==== STRUCTS ====//

typedef struct s_Ouroboros{
	int					rank;
	int					inverse_rank;
	int					data;
	struct s_Ouroboros	*partner;
	struct s_Ouroboros	*next;
	struct s_Ouroboros	*previous;
}t_Ouroboros;

typedef struct s_stacks{
	struct s_Ouroboros	*stack_a;
	struct s_Ouroboros	*stack_b;
}t_stacks;

//=============== LIST MANAGEMENT =============//

int				ft_create_list(t_Ouroboros **snake_head, char **argv);
t_Ouroboros		*ft_list_min_is(t_Ouroboros **snake_head);
int				ft_is_sorted(t_Ouroboros **snake_head);
int				ft_list_len(t_Ouroboros **snake_head);
void			ft_find_rank(t_Ouroboros **snake_head);

//=============== ALGORITHM =============//

void			ft_sort_2(t_Ouroboros **snake_head, t_Ouroboros *a);
void			ft_sort_3(t_Ouroboros **snake_head);
void			ft_sort_3_1(t_Ouroboros **snake_head, t_Ouroboros *a,
					t_Ouroboros *b, t_Ouroboros *c);
void			ft_sort_4(t_Ouroboros **stack_a, t_Ouroboros **stack_b);
void			ft_sort_5(t_Ouroboros **stack_a, t_Ouroboros **stack_b);
void			choose_algo(t_Ouroboros **snake_head, t_Ouroboros **b, int len);
t_Ouroboros		*find_partner(t_Ouroboros *stack_a, t_Ouroboros *node_b);

//=================== OPERATIONS =============//

t_Ouroboros		*ft_pop(t_Ouroboros **current, int x);
void			ft_swap(t_Ouroboros **snake_head);
void			ft_swap_a(t_Ouroboros **a,
					__attribute__ ((unused)) t_Ouroboros **b);
void			ft_swap_b(__attribute__ ((unused)) t_Ouroboros **a,
					t_Ouroboros **b);
void			ft_push(t_Ouroboros **snake_head, t_Ouroboros *new_node);
void			ft_push_to_b(t_Ouroboros **a, t_Ouroboros **b);
void			ft_push_to_a(t_Ouroboros **a, t_Ouroboros **b);
void			ft_rotate(t_Ouroboros **snake_head);
void			ft_rotate_a(t_Ouroboros **a,
					__attribute__ ((unused)) t_Ouroboros **b);
void			ft_rotate_b(__attribute__ ((unused)) t_Ouroboros **a,
					t_Ouroboros **b);
void			ft_rotate_both(t_Ouroboros **a, t_Ouroboros **b);
void			ft_reverse_rotate(t_Ouroboros **snake_head);
void			ft_RR_a(t_Ouroboros **a,
					__attribute__ ((unused)) t_Ouroboros **b);
void			ft_RR_b(__attribute__ ((unused)) t_Ouroboros **a,
					t_Ouroboros **b);
void			ft_RR_both(t_Ouroboros **a, t_Ouroboros **b);

//===== ERROR HANDLING AND FREE MEMORY ====//

int				ft_error(t_Ouroboros **snake_head, char **input);
void			ft_free_list(t_Ouroboros **snake_head);
int				ft_free_split(char **input);
int				ft_check_doubles(t_Ouroboros **snake_head);
int				ft_is_int(char **input);

#endif
