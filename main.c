/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngalzand <ngalzand@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 09:47:14 by ngalzand          #+#    #+#             */
/*   Updated: 2023/01/04 09:47:19 by ngalzand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_struct	*init_struct(void)
{
	t_struct	*pshswp;

	pshswp = (t_struct *)malloc(sizeof(t_struct));
	if (!pshswp)
		put_error(0);
	pshswp->max_len = 0;
	pshswp->a_len = 0;
	pshswp->b_len = 0;
	pshswp->original = 0;
	pshswp->pile_a = 0;
	pshswp->pile_b = 0;
	return (pshswp);
}

static void	three(t_struct *push_swap)
{
	if (push_swap->pile_a[0] > push_swap->pile_a[1])
		swap(push_swap, 'a');
	if (!is_sorted(push_swap->pile_a, push_swap->a_len))
		reverse_rotate(push_swap, 'a');
	if (push_swap->pile_a[0] > push_swap->pile_a[1])
		swap(push_swap, 'a');
}

int	main(int argc, char **argv)
{
	t_struct	*push_swap;

	if (argc < 2)
		return (0);
	push_swap = init_tabs(argc, argv);
	if (push_swap->max_len == 1
		|| is_sorted(push_swap->pile_a, push_swap->a_len))
	{
		free_struct(push_swap);
		return (0);
	}
	if (push_swap->max_len == 2)
		swap(push_swap, 'a');
	else if (push_swap->max_len == 3)
		three(push_swap);
	else if (push_swap->max_len <= 25)
		simple_sort(push_swap);
	else
		complex_sort(push_swap);
	free_struct(push_swap);
	return (0);
}
