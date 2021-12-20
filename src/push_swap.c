/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satori <satori@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 23:33:00 by mrojas-e          #+#    #+#             */
/*   Updated: 2021/12/20 14:25:17 by satori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h> 
#include <stdio.h> 

#include "../includes/push_swap.h"

void	ft_create_new_node(t_Ouroboros **snake_head, int input)
{
	t_Ouroboros	*new_node;

	new_node = malloc(sizeof(t_Ouroboros));
	if (new_node == NULL)
		return ;
	new_node->data = input;
	ft_push(snake_head, new_node);
	ft_rotate(snake_head);
}

int	ft_create_list(t_Ouroboros **snake_head, char **argv)
{
	int		i;
	int		j;
	char	**input;

	i = 1;
	while (argv[i])
	{	
		input = ft_split(argv[i], ' ');
		if (ft_is_int(input) == ERROR)
			return (ft_error(NULL, input));
		j = 0;
		while (input[j])
			ft_create_new_node(snake_head, ft_atoi(input[j++]));
		ft_free_split(input);
		i++;
	}
	if (ft_check_doubles(snake_head) == ERROR)
		return (ft_error(snake_head, NULL));
	return (0);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc < 2)
		return (0);
	stacks.stack_b = 0;
	stacks.stack_a = 0;
	if (ft_create_list(&stacks.stack_a, argv) == ERROR)
		return (ERROR);
	ft_find_rank(&stacks.stack_a);
	choose_algo(&stacks.stack_a, &stacks.stack_b, ft_list_len(&stacks.stack_a));
	ft_free_list(&stacks.stack_a);
	ft_free_list(&stacks.stack_b);
	stacks.stack_a = NULL;
	stacks.stack_b = NULL;
}
