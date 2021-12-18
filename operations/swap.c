/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satori <satori@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 23:20:04 by mrojas-e          #+#    #+#             */
/*   Updated: 2021/12/17 18:16:28 by satori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*====Swap Functions====*/
/* The swap function only changes the top 2 values by
changing the data variable of each node*/

void	ft_swap(t_Ouroboros **stackA_B)
{
	int	temp;
	int	temp_rank;
	int	temp_irank;

	temp = (*stackA_B)->data;
	temp_rank = (*stackA_B)->rank;
	temp_irank = (*stackA_B)->inverse_rank;
	(*stackA_B)->data = (*stackA_B)->next->data;
	(*stackA_B)->rank = (*stackA_B)->next->rank;
	(*stackA_B)->inverse_rank = (*stackA_B)->next->inverse_rank;
	(*stackA_B)->next->data = temp;
	(*stackA_B)->next->rank = temp_rank;
	(*stackA_B)->next->inverse_rank = temp_irank;
	return ;
}

void	ft_swap_A(t_Ouroboros **a,
		__attribute__ ((unused)) t_Ouroboros **b)
{
	ft_swap(a);
	make_fabulous("sa\n", CYAN);

}

void	ft_swap_B(__attribute__ ((unused)) t_Ouroboros **a, t_Ouroboros **b)
{
	ft_swap(b);
	make_fabulous("sb\n", CYAN);

}

void	ft_swap_both(t_Ouroboros **a, t_Ouroboros **b)
{
	ft_swap(a);
	ft_swap(b);
	make_fabulous("ss\n", CYAN);
}
