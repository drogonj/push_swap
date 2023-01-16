/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngalzand <ngalzand@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 09:47:32 by ngalzand          #+#    #+#             */
/*   Updated: 2023/01/04 09:47:35 by ngalzand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r' || c == ' ')
		return (1);
	return (0);
}

static void	atoi_error(t_struct *pshswp, char *str, int isallocated)
{
	if (isallocated == 1)
		free(str);
	put_error(pshswp);
}

int	ft_atoi_ps(t_struct *pshswp, char *str, int isallocated)
{
	size_t				i;
	int					sign;
	long long int		res;

	i = 0;
	sign = 1;
	res = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = ((res * 10) + str[i] - '0');
		i++;
	}
	if (res * sign > 2147483647 || res * sign < -2147483648)
		atoi_error(pshswp, str, isallocated);
	return ((int)(res * sign));
}
