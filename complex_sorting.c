/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sorting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngalzand <ngalzand@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 09:47:26 by ngalzand          #+#    #+#             */
/*   Updated: 2023/01/04 10:05:24 by ngalzand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort(t_struct *ps)
{
	while (ps->b_len > 0)
	{
		while (ps->pile_b[0] != ps->pile_b[get_biggest(ps, 'b')])
		{
			if (fastest_get_b(ps, get_biggest(ps, 'b'), 2) == 1)
				rotate(ps, 'b');
			else if (fastest_get_b(ps, get_biggest(ps, 'b'), 2) == 0)
				reverse_rotate(ps, 'b');
		}
		push(ps, 'a');
	}
}

static void	arrange_a(t_struct *ps, double nsave, double n, double multiplier)
{
	int	i;

	while (n <= nsave + 1 && ps->a_len > 0)
	{
		i = detect_nbr(ps, n, 'a');
		while (i >= 0)
		{
			if (ps->pile_a[0] <= n)
			{
				push(ps, 'b');
				i--;
			}
			else if (fastest_get_a(ps, n, 1) == 1)
				rotate(ps, 'a');
			else if (fastest_get_a(ps, n, 1) == 0)
				reverse_rotate(ps, 'a');
		}
		n += ps->max_len / multiplier;
	}
}

static void	arrange_b(t_struct *ps, double nsave, double n, double multiplier)
{
	int	i;

	while (n <= nsave && ps->b_len > 0)
	{
		i = detect_nbr(ps, n, 'b');
		while (i >= 0)
		{
			if (ps->pile_b[0] <= n)
			{
				push(ps, 'a');
				i--;
			}
			else if (fastest_get_b(ps, n, 1) == 1 && ps->pile_b[0] > n)
				rotate(ps, 'b');
			else if (fastest_get_b(ps, n, 1) == 0)
				reverse_rotate(ps, 'b');
		}
		n += ps->max_len / multiplier;
	}
}

void	complex_sort(t_struct *ps)
{
	if (ps->max_len <= 200)
	{
		arrange_a(ps, ps->max_len, ps->max_len / 6, 6);
	}
	if (ps->max_len > 200)
	{
		arrange_a(ps, ps->max_len, ps->max_len / 4, 4);
		arrange_b(ps, ps->max_len, ps->max_len / 16, 16);
		arrange_a(ps, ps->max_len, ps->max_len / 64, 64);
	}
	sort(ps);
}
