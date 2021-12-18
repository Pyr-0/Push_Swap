/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satori <satori@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:51:42 by satori            #+#    #+#             */
/*   Updated: 2021/12/16 14:02:10 by satori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_find_rank(t_Ouroboros **snake_head)
{
	t_Ouroboros *current;
	t_Ouroboros *temp;
	int	rank;
	int elements_total;

	elements_total = ft_list_len(snake_head);
	current = *snake_head;
	while(1)
	{
		temp = *snake_head;
		rank = 0;
		while(1)
		{
			temp = temp->next;
			if (temp->data < current->data)
				rank++;
			if (temp == *snake_head)
				break;
		}
		current->rank = rank;
		current->inverse_rank = elements_total - rank - 1;
		current = current->next;
		if (current == *snake_head)
			break;
	}
}

t_Ouroboros *find_partner(t_Ouroboros *stack_a, t_Ouroboros *node_b)
{
	t_Ouroboros *current;

	current = stack_a;
	while(1)
	{
		current = current->next;
		if ( current->rank >= node_b->rank && current->rank <= current->previous->rank)
			break;
		if (current->rank >= node_b->rank && current->previous->rank <= node_b->rank)
			break;
		if (current ->previous->rank <= node_b->rank && current->rank <= current->previous->rank)
			break;
	}
	return (current);
}
