/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tabs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngalzand <ngalzand@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 09:47:50 by ngalzand          #+#    #+#             */
/*   Updated: 2023/01/04 09:47:52 by ngalzand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_duplicates(int *tab, int len)
{
	int	i;
	int	j;

	i = -1;
	while (++i < len)
	{
		j = i;
		while (++j < len)
			if (tab[i] == tab[j])
				return (1);
	}
	return (0);
}

static int	big_condition(char **argv, int i, int j, int condition)
{
	if (condition == 1)
	{
		if ((argv[1][i] != ' ' && argv[1][i] != '-' && argv[1][i] != '+'
		&& (argv[1][i] < '0' || argv[1][i] > '9'))
		|| ((argv[1][i] == '-' || argv[1][i] == '+') && (!argv[1][i + 1]
		|| argv[1][i + 1] < '0' || argv[1][i + 1] > '9'
		|| (i != 0 && argv[1][i - 1] != ' ')))
		|| (argv[1][i] == ' ' && (!argv[1][i - 1] || argv[1][i - 1] < '0'
		|| argv[1][i - 1] > '9' || !argv[1][i + 1])))
			return (-1);
	}
	if (condition == 2)
	{
		if (((argv[i][j] < '0' || argv[i][j] > '9')
		&& (argv[i][j] != '+' && argv[i][j] != '-'))
		|| ((argv[i][j] == '-' || argv[i][j] == '+')
		&& (!argv[i][j + 1] || j != 0 || argv[i][j + 1] < '0'
		|| argv[i][j + 1] > '9')))
			return (-1);
	}
	return (0);
}

static int	check_args(int *len, int argc, char **argv, int i)
{
	if (argc == 2)
	{
		if (argv[1] && argv[1][0] && ((argv[1][0] >= '0' && argv[1][0] <= '9')
		|| argv[1][0] == '-' || argv[1][0] == '+'))
			*len += 1;
		while (argv[1][++i])
		{
			if (big_condition(argv, i, 0, 1) == -1)
				return (-1);
			else if (argv[1][i] == ' ')
				*len += 1;
		}
		return (1);
	}
	i++;
	while (argv[++i])
	{
		argc = -1;
		while (argv[i][++argc])
			if (big_condition(argv, i, argc, 2) == -1)
				return (-1);
	}
	*len = i - 1;
	return (2);
}

static void	get_tab(t_struct *pshswp, int argc, char **argv)
{
	int	i;

	i = 0;
	pshswp->original = (int *)ft_calloc(argc - 1, sizeof(int));
	if (!pshswp->original)
		put_error(free_struct(pshswp));
	while (argv[++i])
		pshswp->original[i - 1] = ft_atoi_ps(pshswp, argv[i], 0);
}

t_struct	*init_tabs(int argc, char **argv)
{
	t_struct	*pshswp;
	int			len;
	int			mode;

	len = 0;
	pshswp = init_struct();
	mode = check_args(&len, argc, argv, -1);
	if (mode == -1)
		put_error(free_struct(pshswp));
	pshswp->max_len = len;
	pshswp->a_len = len;
	if (mode == 1)
		ft_split_ps(pshswp, argv[1], ' ');
	if (mode == 2)
		get_tab(pshswp, argc, argv);
	malloc_piles(pshswp, argc, mode);
	if (check_duplicates(pshswp->original, pshswp->max_len))
		put_error(free_struct(pshswp));
	make_pile_a(pshswp);
	return (pshswp);
}
