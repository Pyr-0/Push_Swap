/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satori <satori@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:42:53 by mrojas-e          #+#    #+#             */
/*   Updated: 2021/12/17 22:56:31 by satori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "push_swap.h"

/* =====FREE WILLY 🐋 =======*/

void	ft_free_list(t_Ouroboros **snake_head)
{
	while (snake_head != NULL && (*snake_head) != NULL)
		ft_pop(snake_head, 1);
}

int	ft_free_split(char **input)
{
	int	a;

	a = 0;
	while (input[a] != NULL)
		free (input[a++]);
	free(input);
	return (ERROR);
}

//printing thh actual error

int	ft_error(t_Ouroboros **snake_head, char **input)
{
	if (input != NULL)
		ft_free_split(input);
	if (snake_head != NULL)
		ft_free_list(snake_head);

	make_fabulous("Error\n", RED);
	return (ERROR);
}

/*====CHECK FOR INTS (LIMITS TOO)*/

int	ft_is_int(char **input)
{
	int		i;
	char	*overflow;

	i = 0;
	while (input[i])
	{
		overflow = ft_itoa(ft_atoi(input[i]));
		if (ft_strncmp(overflow, input[i], ft_strlen(input[i])) != 0)
		{
			free(overflow);
			return (ERROR);
		}
		i++;
		free(overflow);
	}
	return (1);
}

/*=====CHECK FOR REPEATED INPUT=====*/

int	ft_check_doubles(t_Ouroboros **snake_head)
{
	t_Ouroboros	*x;
	t_Ouroboros	*y;

	x = *snake_head;
	while (1)
	{
		y = *snake_head;
		while (1)
		{
			if (x != y && x->data == y->data)
				return (ERROR);
			y = y->next;
			if (y == *snake_head)
				break ;
		}
		x = x->next;
		if (x == *snake_head)
			break ;
	}
	return (1);
}
