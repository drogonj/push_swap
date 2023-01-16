/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngalzand <ngalzand@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:36:15 by ngalzand          #+#    #+#             */
/*   Updated: 2023/01/04 10:36:18 by ngalzand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	detect_nbr(t_struct *ps, int n, char pile)
{
	int	i;
	int	res;

	i = -1;
	res = 0;
	if (pile == 'a')
	{
		while (++i < ps->a_len)
			if (ps->pile_a[i] < n)
				res++;
	}
	if (pile == 'b')
	{
		while (++i < ps->b_len)
			if (ps->pile_b[i] < n)
				res++;
	}
	return (res);
}

int	fastest_get_b(t_struct *ps, double n, int mode)
{
	int	i;
	int	count_front;
	int	count_back;

	i = -1;
	count_front = 0;
	count_back = 0;
	if (mode == 1)
	{
		while (++i < ps->b_len && ps->pile_b[i] > n)
			count_front++;
		i = ps->b_len;
		while (--i > 0 && ps->pile_b[i] > n)
			count_back++;
	}
	else
	{
		while (++i < ps->b_len && i != n)
			count_front++;
		i = ps->b_len;
		while (--i > 0 && i != n)
			count_back++;
	}
	return (count_front < count_back);
}

int	fastest_get_a(t_struct *ps, double n, int mode)
{
	int	i;
	int	count_front;
	int	count_back;

	i = -1;
	count_front = 0;
	count_back = 0;
	if (mode == 1)
	{
		while (++i < ps->a_len && ps->pile_a[i] > n)
			count_front++;
		i = ps->a_len;
		while (--i > 0 && ps->pile_a[i] > n)
			count_back++;
	}
	else
	{
		while (++i < ps->a_len && i != n)
			count_front++;
		i = ps->a_len;
		while (--i > 0 && i != n)
			count_back++;
	}
	return (count_front < count_back);
}

int	get_biggest(t_struct *ps, char pile)
{
	int	i;
	int	save;

	i = -1;
	save = -1;
	if (pile == 'a')
	{
		while (++i < ps->a_len)
			if (save == -1 || ps->pile_a[i] > ps->pile_a[save])
				save = i;
	}
	if (pile == 'b')
	{
		while (++i < ps->b_len)
			if (save == -1 || ps->pile_b[i] > ps->pile_b[save])
				save = i;
	}
	return (save);
}

int	get_smallest(t_struct *ps, char pile)
{
	int	i;
	int	save;

	i = -1;
	save = -1;
	if (pile == 'a')
	{
		while (++i < ps->a_len)
			if (save == -1 || ps->pile_a[i] < ps->pile_a[save])
				save = i;
	}
	if (pile == 'b')
	{
		while (++i < ps->b_len)
			if (save == -1 || ps->pile_b[i] < ps->pile_b[save])
				save = i;
	}
	return (save);
}
