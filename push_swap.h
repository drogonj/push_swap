/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngalzand <ngalzand@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 09:48:03 by ngalzand          #+#    #+#             */
/*   Updated: 2023/01/04 09:48:04 by ngalzand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_struct
{
	int		max_len;
	int		a_len;
	int		b_len;
	int		*original;
	int		*pile_a;
	int		*pile_b;
}	t_struct;

// Init //
t_struct	*init_struct(void);
t_struct	*init_tabs(int argc, char **argv);
int			ft_split_ps(t_struct *pshswp, char *str, char c);
int			ft_atoi_ps(t_struct *pshswp, char *str, int isallocated);
void		malloc_piles(t_struct *pshswp, int argc, int mode);
void		make_pile_a(t_struct *ps);

// Instructions //
void		swap(t_struct *push_swap, char pile);
void		push(t_struct *push_swap, char pile);
void		rotate(t_struct *push_swap, char pile);
void		reverse_rotate(t_struct *push_swap, char pile);

// Sorting //
void		simple_sort(t_struct *ps);
void		complex_sort(t_struct *ps);

// Utils //
int			is_sorted(int *pile, int len);
void		*free_struct(t_struct *pshswp);
int			put_error(void	*null);
void		move_right(t_struct *ps, char pile, int value);
void		move_left(t_struct *ps, char pile);
int			detect_nbr(t_struct *ps, int n, char pile);
int			fastest_get_a(t_struct *ps, double n, int mode);
int			fastest_get_b(t_struct *ps, double n, int mode);
int			get_biggest(t_struct *ps, char pile);
int			get_smallest(t_struct *ps, char pile);

#endif
