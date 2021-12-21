/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satori <satori@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:13:09 by satori            #+#    #+#             */
/*   Updated: 2021/12/20 16:27:27 by satori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	radix_bit_filter(t_Ouroboros **stack_a, int i)
{
	int			elements_processed;
	int			elements_total;
	t_Ouroboros	*temp;

	elements_total = ft_list_len(stack_a);
	temp = *stack_a;
	elements_processed = 0;
	while (elements_processed < elements_total)
	{
		if (((temp)->inverse_rank & (1 << i)))
			return (1);
		elements_processed ++;
		temp = temp->next;
	}
	return (0);
}

void	ft_radix_sort(t_Ouroboros **stack_a, t_Ouroboros **stack_b)
{
	int	i;
	int	elements_processed;
	int	elements_total;

	i = 0;
	elements_total = ft_list_len(stack_a);
	while (i < 32)
	{
		if (radix_bit_filter(stack_a, i) == 1)
		{
			elements_processed = 0;
			while (elements_processed < elements_total)
			{
				if (((*stack_a)->inverse_rank & (1 << i)))
					ft_push_to_b(stack_a, stack_b);
				else
					ft_rotate_a(stack_a, stack_b);
				elements_processed ++;
			}
			while (ft_list_len(stack_b) != 0)
				ft_push_to_a(stack_a, stack_b);
		}
		i++;
	}
}

void	choose_algo(t_Ouroboros **stack_a, t_Ouroboros **stack_b, int len)
{
	if (len <= 3)
		ft_sort_3(stack_a);
	else if (len == 4)
		ft_sort_4(stack_a, stack_b);
	else if (len == 5)
		ft_sort_5(stack_a, stack_b);
	else if (len >= 6 && ft_is_sorted(stack_a))
		return ;
	else
		ft_radix_sort(stack_a, stack_b);
}
