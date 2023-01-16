/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngalzand <ngalzand@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 09:48:07 by ngalzand          #+#    #+#             */
/*   Updated: 2023/01/04 09:48:09 by ngalzand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_smallest_s(t_struct *ps)
{
	int	i;
	int	save;

	i = -1;
	save = -1;
	while (++i < ps->a_len)
		if (save == -1 || ps->pile_a[i] < ps->pile_a[save])
			save = i;
	return (save);
}

static void	move_smallest(t_struct *ps)
{
	int	small;

	small = get_smallest_s(ps);
	if (small <= ps->a_len / 2)
	{
		while (small != 0)
		{
			rotate(ps, 'a');
			small = get_smallest_s(ps);
		}
	}
	else
	{
		while (small != 0)
		{
			reverse_rotate(ps, 'a');
			small = get_smallest_s(ps);
		}
	}
	if (!is_sorted(ps->pile_a, ps->a_len))
		push(ps, 'b');
}

void	simple_sort(t_struct *ps)
{
	while (ps->a_len != 0 && !is_sorted(ps->pile_a, ps->a_len))
		move_smallest(ps);
	while (ps->b_len != 0)
		push(ps, 'a');
}
