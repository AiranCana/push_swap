/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raqroca- <raqroca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 10:41:14 by raqroca-          #+#    #+#             */
/*   Updated: 2026/03/03 11:03:01 by raqroca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
simple:
	- The goal is to reduce stack A until only 3 elements remain.
	- In each iteration, find the smallest number (min) in A.
	- Calculate the distance from min to the top to choose the shortest path:
	- If it is in the first half, use normal rotation (ra).
	- If it is in the second half, use reverse rotation (rra).
	- Send the smallest element to B (pb).
	- Once there are 3 elements left, apply a specific sort (sort_three).
	- Finally, return all elements from B to A (pa) already sorted.
*/

static void	push_min_to_b(t_stack **stack)
{
	int	min;
	int	pos;
	int	size;

	size = ft_lstsize((*stack)->stacka);
	min = get_min((*stack)->stacka);
	pos = get_position((*stack)->stacka, min);
	if (pos <= size / 2)
	{
		while ((*stack)->stacka->num != min)
			ra(stack);
	}
	else
	{
		while ((*stack)->stacka->num != min)
			rra(stack);
	}
	pb(stack);
}

void	simple(t_stack **stack)
{
	int	size;

	if (!stack || !(*stack) || !(*stack)->stacka)
		return ;
	size = ft_lstsize((*stack)->stacka);
	if (size <= 3)
	{
		tiny_sort(stack);
		return ;
	}
	while (ft_lstsize((*stack)->stacka) > 3)
		push_min_to_b(stack);
	tiny_sort(stack);
	while ((*stack)->stackb != NULL)
		pa(stack);
}
