/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngalzand <ngalzand@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 09:47:55 by ngalzand          #+#    #+#             */
/*   Updated: 2023/01/04 09:47:57 by ngalzand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_struct *push_swap, char pile)
{
	int	tmp;

	if ((pile == 'a' || pile == 's') && push_swap->a_len > 1)
	{
		tmp = push_swap->pile_a[0];
		push_swap->pile_a[0] = push_swap->pile_a[1];
		push_swap->pile_a[1] = tmp;
	}
	if ((pile == 'b' || pile == 's') && push_swap->b_len > 1)
	{
		tmp = push_swap->pile_b[0];
		push_swap->pile_b[0] = push_swap->pile_b[1];
		push_swap->pile_b[1] = tmp;
	}
	ft_printf("s%c\n", pile);
}

void	push(t_struct *push_swap, char pile)
{
	if (pile == 'a' && push_swap->b_len > 0
		&& (push_swap->a_len < push_swap->max_len))
	{
		move_right(push_swap, 'a', push_swap->pile_b[0]);
		move_left(push_swap, 'b');
	}
	if (pile == 'b' && push_swap->a_len > 0
		&& (push_swap->b_len < push_swap->max_len))
	{
		move_right(push_swap, 'b', push_swap->pile_a[0]);
		move_left(push_swap, 'a');
	}
	ft_printf("p%c\n", pile);
}

void	reverse_rotate(t_struct *ps, char pile)
{
	int	i;
	int	tmp;

	if ((pile == 'a' || pile == 'r') && ps->a_len > 1)
	{
		i = ps->a_len;
		while (--i > 0)
		{
			tmp = ps->pile_a[(i - 1) % ps->a_len];
			ps->pile_a[(i - 1) % ps->a_len] = ps->pile_a[i];
			ps->pile_a[i] = tmp;
		}
	}
	if ((pile == 'b' || pile == 'r') && ps->b_len > 1)
	{
		i = ps->b_len;
		while (--i > 0)
		{
			tmp = ps->pile_b[(i - 1) % ps->b_len];
			ps->pile_b[(i - 1) % ps->b_len] = ps->pile_b[i];
			ps->pile_b[i] = tmp;
		}
	}
	ft_printf("rr%c\n", pile);
}

void	rotate(t_struct *ps, char pile)
{
	int	i;
	int	tmp;

	if ((pile == 'a' || pile == 'r') && ps->a_len > 1)
	{
		i = 0;
		while (++i < ps->a_len)
		{
			tmp = ps->pile_a[(i - 1) % ps->a_len];
			ps->pile_a[(i - 1) % ps->a_len] = ps->pile_a[i];
			ps->pile_a[i] = tmp;
		}
	}
	if ((pile == 'b' || pile == 'r') && ps->b_len > 1)
	{
		i = 0;
		while (++i < ps->b_len)
		{
			tmp = ps->pile_b[(i - 1) % ps->b_len];
			ps->pile_b[(i - 1) % ps->b_len] = ps->pile_b[i];
			ps->pile_b[i] = tmp;
		}
	}
	ft_printf("r%c\n", pile);
}
