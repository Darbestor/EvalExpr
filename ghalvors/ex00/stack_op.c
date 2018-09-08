/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghalvors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 21:05:01 by ghalvors          #+#    #+#             */
/*   Updated: 2018/09/08 21:07:42 by ghalvors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

t_stack_op	*ft_stack_op_new(char op)
{
	t_stack_op *st;

	if (!(st = (t_stack_op*)malloc(sizeof(t_stack_op))))
		return (NULL);
	st->op = op;
	st->next = NULL;
	return (st);
}

void		ft_stack_op_push(t_stack_op **st, char op)
{
	t_stack_op	*item;
	t_stack_op	*temp;

	item = ft_stack_op_new(op);
	temp = *st;
	*st = item;
	item->next = temp;
}

char		ft_stack_op_pop(t_stack_op **head)
{
	char		retval;
	t_stack_op	*temp;

	if (!*head)
	{
		retval = (*head)->op;
		free(*head);
		return (retval);
	}
	temp = *head;
	retval = (*head)->op;
	*head = (*head)->next;
	free(temp);
	return (retval);
}
