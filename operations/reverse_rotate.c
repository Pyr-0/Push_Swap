/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satori <satori@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 23:23:55 by mrojas-e          #+#    #+#             */
/*   Updated: 2021/12/17 18:21:25 by satori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*====Reverse Rotate Functions====*/

void	ft_reverse_rotate(t_Ouroboros **snake_head)
{
	*snake_head = (*snake_head)->previous;
	return ;
}

void	ft_RR_A(t_Ouroboros **a, __attribute__ ((unused)) t_Ouroboros **b)
{
	ft_reverse_rotate(a);
	make_fabulous("rra\n", CYAN);
}

void	ft_RR_B(__attribute__ ((unused)) t_Ouroboros **a, t_Ouroboros **b)
{
	ft_reverse_rotate(b);
	make_fabulous("rrb\n", CYAN);
}

void	ft_RR_both(t_Ouroboros **a, t_Ouroboros **b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	make_fabulous("rrr\n", CYAN);
}
