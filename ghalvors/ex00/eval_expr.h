/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghalvors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 10:06:27 by ghalvors          #+#    #+#             */
/*   Updated: 2018/09/08 21:05:20 by ghalvors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVAL_EXPR_H
# define EVAL_EXPR_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_stack_nbrs
{
	int					nbr;
	struct s_stack_nbrs *next;
}				t_stack_nbr;

typedef struct	s_stack_op
{
	char				op;
	struct s_stack_op	*next;
}				t_stack_op;

void			ft_putnbr(int nbr);
void			ft_putchar(char c);
int				eval_expr(char *str);
t_stack_nbr		*ft_stack_nbr_new(int nbr);
void			ft_stack_nbr_push(t_stack_nbr **st, int nbr);
int				ft_stack_nbr_pop(t_stack_nbr **head);
t_stack_op		*ft_stack_op_new(char op);
void			ft_stack_op_push(t_stack_op **st, char op);
char			ft_stack_op_pop(t_stack_op **head);

#endif
