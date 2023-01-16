/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngalzand <ngalzand@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 09:47:43 by ngalzand          #+#    #+#             */
/*   Updated: 2023/01/04 09:47:45 by ngalzand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_pile_a(t_struct *ps)
{
	int	i;
	int	j;

	i = -1;
	while (++i < ps->max_len)
	{
		j = -1;
		while (++j < ps->max_len)
		{
			if (ps->original[i] > ps->original[j])
				ps->pile_a[i]++;
		}
	}
}

int	is_sorted(int *pile, int len)
{
	int	i;

	i = 0;
	while (++i < len)
		if (pile[i] < pile[i - 1])
			return (0);
	return (1);
}

void	malloc_piles(t_struct *pshswp, int argc, int mode)
{
	if (mode == 1)
	{
		pshswp->pile_a = (int *) ft_calloc(pshswp->max_len, sizeof(int));
		pshswp->pile_b = (int *) ft_calloc(pshswp->max_len, sizeof(int));
	}
	else
	{
		pshswp->pile_a = (int *)ft_calloc(argc - 1, sizeof(int));
		pshswp->pile_b = (int *)ft_calloc(argc - 1, sizeof(int));
	}
	if (!pshswp->pile_a || !pshswp->pile_b)
		put_error(free_struct(pshswp));
}

void	*free_struct(t_struct *pshswp)
{
	if (!pshswp)
		exit(1);
	if (pshswp->original)
		free((*pshswp).original);
	if (pshswp->pile_a)
		free((*pshswp).pile_a);
	if (pshswp->pile_b)
		free((*pshswp).pile_b);
	free(pshswp);
	return (0);
}

int	put_error(void	*null)
{
	(void)null;
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
