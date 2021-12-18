/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satori <satori@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 23:21:30 by mrojas-e          #+#    #+#             */
/*   Updated: 2021/12/17 18:18:03 by satori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*====Rotate functions====*/

void	ft_rotate(t_Ouroboros **snake_head)
{
	*snake_head = (*snake_head)->next;
	return ;
}

void	ft_rotate_A(t_Ouroboros **a, __attribute__ ((unused)) t_Ouroboros **b)
{
	ft_rotate(a);
	make_fabulous("ra\n", CYAN);
}

void	ft_rotate_B(__attribute__ ((unused)) t_Ouroboros **a, t_Ouroboros **b)
{
	ft_rotate(b);
	make_fabulous("rb\n", CYAN);
}

void	ft_rotate_both(t_Ouroboros **a, t_Ouroboros **b)
{
	ft_rotate(a);
	ft_rotate(b);
	make_fabulous("rr\n", CYAN);
}
