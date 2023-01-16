/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngalzand <ngalzand@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:49:33 by ngalzand          #+#    #+#             */
/*   Updated: 2023/01/04 10:49:37 by ngalzand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_right(t_struct *ps, char pile, int value)
{
	int	i;

	if (pile == 'a')
	{
		ps->a_len++;
		i = ps->a_len;
		while (--i > 0)
			ps->pile_a[i] = ps->pile_a[i - 1];
		ps->pile_a[i] = value;
	}
	if (pile == 'b')
	{
		ps->b_len++;
		i = ps->b_len;
		while (--i > 0)
			ps->pile_b[i] = ps->pile_b[i - 1];
		ps->pile_b[i] = value;
	}
}

void	move_left(t_struct *ps, char pile)
{
	int	i;

	i = 0;
	if (pile == 'a')
	{
		while (++i < ps->a_len)
			ps->pile_a[i - 1] = ps->pile_a[i];
		ps->a_len--;
	}
	if (pile == 'b')
	{
		while (++i < ps->b_len)
			ps->pile_b[i - 1] = ps->pile_b[i];
		ps->b_len--;
	}
}
