/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satori <satori@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 23:20:04 by mrojas-e          #+#    #+#             */
/*   Updated: 2021/12/20 15:55:16 by satori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*====Swap Functions====*/
/* The swap function only changes the top 2 values by
changing the data variable of each node*/

void	ft_swap(t_Ouroboros **stacka_b)
{
	int	temp;
	int	temp_rank;
	int	temp_irank;

	temp = (*stacka_b)->data;
	temp_rank = (*stacka_b)->rank;
	temp_irank = (*stacka_b)->inverse_rank;
	(*stacka_b)->data = (*stacka_b)->next->data;
	(*stacka_b)->rank = (*stacka_b)->next->rank;
	(*stacka_b)->inverse_rank = (*stacka_b)->next->inverse_rank;
	(*stacka_b)->next->data = temp;
	(*stacka_b)->next->rank = temp_rank;
	(*stacka_b)->next->inverse_rank = temp_irank;
	return ;
}

void	ft_swap_a(t_Ouroboros **a, __attribute__ ((unused)) t_Ouroboros **b)
{
	ft_swap(a);
	ft_putstr_fd("sa\n", 1);
}

void	ft_swap_b(__attribute__ ((unused)) t_Ouroboros **a, t_Ouroboros **b)
{
	ft_swap(b);
	ft_putstr_fd("sb\n", 1);
}

void	ft_swap_both(t_Ouroboros **a, t_Ouroboros **b)
{
	ft_swap(a);
	ft_swap(b);
	ft_putstr_fd("ss\n", 1);
}
