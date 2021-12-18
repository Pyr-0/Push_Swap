/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satori <satori@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 23:25:47 by mrojas-e          #+#    #+#             */
/*   Updated: 2021/12/17 19:06:08 by satori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*====Push Functions====*/

void	ft_push(t_Ouroboros **snake_head, t_Ouroboros *new_node)
{
	if (!new_node)
		return ;
	if (*snake_head == NULL)
	{
		new_node->previous = new_node;
		new_node->next = new_node;
		*snake_head = new_node;
	}
	else
	{
		(*snake_head)->previous->next = new_node;
		new_node->previous = (*snake_head)->previous;
		(*snake_head)->previous = new_node;
		new_node->next = *snake_head;
		*snake_head = new_node;
	}
}

void	ft_push_to_A(t_Ouroboros **a, t_Ouroboros **b)
{
	ft_push(a, ft_pop(b, 0));
/* 	write(1, CYAN, 7);
	write(1, "pa\n", 3);
	write(1, RESET, 7); */
	make_fabulous("pa\n", NULL);
}

void	ft_push_to_B(t_Ouroboros **a, t_Ouroboros **b)
{
	ft_push(b, ft_pop(a, 0));
	make_fabulous("pb\n", NULL);
}

t_Ouroboros	*ft_pop(t_Ouroboros **snake_head, int x)
{
	t_Ouroboros	*temp;

	if (snake_head == NULL || *snake_head == NULL)
		return (NULL);
	temp = *snake_head;
	if (*snake_head == (*snake_head)->previous)
	{	
		if (x == 1)
			free(*snake_head);
		*snake_head = NULL;
		return (temp);
	}
	*snake_head = temp->next;
	(*snake_head)->previous = temp->previous;
	(*snake_head)->previous->next = *snake_head;
	temp->next = temp;
	temp->previous = temp;
	if (x == 1)
		free(temp);
	return (temp);
}
