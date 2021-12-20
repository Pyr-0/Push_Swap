/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satori <satori@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 23:23:55 by mrojas-e          #+#    #+#             */
/*   Updated: 2021/12/20 15:54:32 by satori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*====Reverse Rotate Functions====*/

void	ft_reverse_rotate(t_Ouroboros **snake_head)
{
	*snake_head = (*snake_head)->previous;
	return ;
}

void	ft_rr_a(t_Ouroboros **a, __attribute__ ((unused)) t_Ouroboros **b)
{
	ft_reverse_rotate(a);
	ft_putstr_fd("rra\n", 1);
}

void	ft_rr_b(__attribute__ ((unused)) t_Ouroboros **a, t_Ouroboros **b)
{
	ft_reverse_rotate(b);
	ft_putstr_fd("rrb\n", 1);
}

void	ft_rr_both(t_Ouroboros **a, t_Ouroboros **b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	ft_putstr_fd("rrr\n", 1);
}
