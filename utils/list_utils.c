/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satori <satori@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 23:01:03 by mrojas-e          #+#    #+#             */
/*   Updated: 2021/12/17 22:55:05 by satori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*====COLOURISE====*/

const char	RAINBOWS[6][7] = {RED, BLUE,PURPLE,CYAN,GREEN,YELLOW};

void	make_fabulous(char *s, char *colour)
{
	static int	i;

	if (colour == NULL)
	{
		write (1, RAINBOWS[i], 7);
		i++;
		if (i == 6)
			i = 0;
	}
	else
	{
		write (1, colour, 7);
		write (1, s, ft_strlen(s));
		write (1, RESET, 7);
	}
}

/*====LIST MANIPULATION====*/

int	ft_list_len(t_Ouroboros **snake_head)
{
	t_Ouroboros	*current;
	int			len;

	if (*snake_head == NULL)
		return (0);
	len = 1;
	current = *snake_head;
	ft_rotate(&current);
	while (current != *snake_head)
	{
		len++;
		current = current->next;
	}
	return (len);
}

t_Ouroboros	*ft_list_min_is(t_Ouroboros **snake_head)
{
	t_Ouroboros	*current;
	int			min;

	current = *snake_head;
	min = current->data;
	current = current->next;
	while (current != *snake_head)
	{
		if (current->data < min)
			min = current->data;
		current = current->next;
	}
	return (current);
}

int	ft_is_sorted(t_Ouroboros **snake_head)
{
	t_Ouroboros	*current;

	current = *snake_head;
	while (1)
	{
		if (current->next == *snake_head)
			break ;
		if (current->data > current->next->data)
			return (0);
		ft_rotate(&current);
	}
	return (1);
}
