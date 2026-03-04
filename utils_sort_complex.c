/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_complex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raqroca- <raqroca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 11:35:12 by raqroca-          #+#    #+#             */
/*   Updated: 2026/03/04 11:44:39 by raqroca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_by_pos(t_stack **stack)
{
	if ((*stack)->stacka->pos > (*stack)->stacka->next->pos)
		sa(stack);
}

void	sort_three_by_pos(t_stack **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->stacka->pos;
	second = (*stack)->stacka->next->pos;
	third = (*stack)->stacka->next->next->pos;
	if (first < second && second < third)
		return ;
	if (first > second && first > third)
	{
		ra(stack);
		if ((*stack)->stacka->pos > (*stack)->stacka->next->pos)
			sa(stack);
	}
	else if (second > first && second > third)
	{
		rra(stack);
		if ((*stack)->stacka->pos > (*stack)->stacka->next->pos)
			sa(stack);
	}
	else
	{
		sa(stack);
	}
}

void	sort_four_by_pos(t_stack **stack)
{
	while ((*stack)->stacka->pos != 0)
		ra(stack);
	pb(stack);
	sort_three_by_pos(stack);
	pa(stack);
}

void	sort_five_by_pos(t_stack **stack)
{
	while ((*stack)->stacka->pos != 0)
		ra(stack);
	pb(stack);
	while ((*stack)->stacka->pos != 1)
		ra(stack);
	pb(stack);
	sort_three_by_pos(stack);
	pa(stack);
	pa(stack);
}

void	tiny_sort_by_pos(t_stack **stack, int size)
{
	if (size == 2)
		sort_two_by_pos(stack);
	else if (size == 3)
		sort_three_by_pos(stack);
	else if (size == 4)
		sort_four_by_pos(stack);
	else if (size == 5)
		sort_five_by_pos(stack);
}
