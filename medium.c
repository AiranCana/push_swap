/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raqroca- <raqroca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 10:32:37 by raqroca-          #+#    #+#             */
/*   Updated: 2026/03/03 16:05:16 by raqroca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sqrt(int n)
{
	int	i;

	if (n <= 0)
		return (0);
	i = 1;
	while (i * i <= n)
		i++;
	return (i - 1);
}

static void	push_max_to_a(t_stack **stack)
{
	int	size;
	int	max_pos;
	int	i;

	size = ft_lstsize((*stack)->stackb);
	max_pos = get_max_index((*stack)->stackb);
	i = get_pos_index((*stack)->stackb, max_pos);
	if (i <= size / 2)
	{
		while ((*stack)->stackb->pos != max_pos)
			rb(stack);
	}
	else
	{
		while ((*stack)->stackb->pos != max_pos)
			rrb(stack);
	}
	pa(stack);
}

void	medium(t_stack **stack)
{
	int	i;
	int	chunk;
	int	size;

	i = 0;
	assign_pos((*stack)->stacka);
	size = ft_lstsize((*stack)->stacka);
	chunk = ft_sqrt(size);
	if (size > 100)
		chunk = chunk * 1.5;
	while ((*stack)->stacka)
	{
		/////from a to b
	}
	while ((*stack)->stackb)
		push_max_to_a(stack);
}
