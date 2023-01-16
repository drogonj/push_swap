/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_ps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngalzand <ngalzand@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 09:47:38 by ngalzand          #+#    #+#             */
/*   Updated: 2023/01/04 09:47:40 by ngalzand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_tab(t_struct *pshswp, char *str, char c, int i)
{
	int		j;
	int		k;
	char	*buffer;
	int		res;

	j = i;
	while (str[j] && str[j] != c)
		j++;
	buffer = (char *)ft_calloc(j - i + 1, sizeof(char));
	if (!buffer)
		put_error(pshswp);
	k = 0;
	while (i < j)
	{
		buffer[k] = str[i];
		k++;
		i++;
	}
	res = ft_atoi_ps(pshswp, buffer, 1);
	free(buffer);
	return (res);
}

int	ft_split_ps(t_struct *pshswp, char *str, char
c)
{
	int			i;
	int			j;

	if (!str || !str[0] || !pshswp)
		put_error(pshswp);
	pshswp->original = (int *)ft_calloc(pshswp->max_len, sizeof(int));
	if (!pshswp->original)
		put_error(pshswp);
	i = 0;
	j = -1;
	while (++j < pshswp->max_len)
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
			pshswp->original[j] = get_tab(pshswp, str, c, i);
		while (str[i] && str[i] != c)
			i++;
	}
	return (0);
}
