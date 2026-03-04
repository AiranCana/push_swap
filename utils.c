/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanadil <acanadil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 12:17:52 by raqroca-          #+#    #+#             */
/*   Updated: 2026/03/04 13:31:50 by acanadil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_list *stack)
{
	int	min;

	if (!stack)
		return (0);
	min = stack->num;
	while (stack)
	{
		if (stack->num < min)
			min = stack->num;
		stack = stack->next;
	}
	return (min);
}

int	get_max(t_list *stack)
{
	int	max;

	if (!stack)
		return (0);
	max = stack->num;
	while (stack)
	{
		if (stack->num > max)
			max = stack->num;
		stack = stack->next;
	}
	return (max);
}

int	is_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (stack->num > stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	get_position(t_list *stack, int value)
{
	int	position;

	if (!stack)
		return (-1);
	position = 0;
	while (stack)
	{
		if (stack->num == value)
			return (position);
		position++;
		stack = stack->next;
	}
	return (-1);
}

int	free_stack(t_stack **stack, t_flags **flags)
{
	ft_flaclear(flags);
	if (!stack || !(*stack))
		return (0);
	ft_lstclear(&((*stack)->stacka));
	ft_lstclear(&((*stack)->stackb));
	free((*stack)->calc);
	free(*stack);
	*stack = NULL;
	return (0);
}
