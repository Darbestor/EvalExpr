/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghalvors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 15:28:22 by ghalvors          #+#    #+#             */
/*   Updated: 2018/09/08 21:08:49 by ghalvors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

t_stack_nbr	*ft_stack_nbr_new(int nbr)
{
	t_stack_nbr *st;

	if (!(st = (t_stack_nbr*)malloc(sizeof(t_stack_nbr))))
		return (NULL);
	st->nbr = nbr;
	st->next = NULL;
	return (st);
}

void		ft_stack_nbr_push(t_stack_nbr **st, int nbr)
{
	t_stack_nbr	*item;
	t_stack_nbr	*temp;

	item = ft_stack_nbr_new(nbr);
	temp = *st;
	*st = item;
	item->next = temp;
}

int			ft_stack_nbr_pop(t_stack_nbr **head)
{
	t_stack_nbr	*temp;
	int			retval;

	if (!(*head)->next)
	{
		retval = (*head)->nbr;
		free(*head);
		return (retval);
	}
	temp = *head;
	retval = (*head)->nbr;
	*head = (*head)->next;
	free(temp);
	return (retval);
}
