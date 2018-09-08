/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghalvors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 10:05:42 by ghalvors          #+#    #+#             */
/*   Updated: 2018/09/08 21:32:20 by ghalvors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

int		ft_atoi(char *str)
{
	int sign;
	int result;

	sign = 1;
	result = 0;
	if (*str == '+' && (*(str + 1) >= '0' || *(str + 1) <= '9'))
		str++;
	if (*str == '-' && (*(str + 1) >= '0' || *(str + 1) <= '9'))
	{
		sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		result = (result * 10) + (*str++ - '0');
	return (result * sign);
}

int		ft_check_stack(t_stack_op *stack, char op)
{
	if (!stack)
		return (1);
	else if ((op == '+' || op == '-') && (stack->op != '('))
		return (0);
	else if ((op == '/' || op == '*' || op == '%') && (stack->op != '(' &&
			stack->op != '+' && stack->op != '-'))
		return (0);
	return (1);
}

void	ft_calc(t_stack_nbr **num, t_stack_op **op)
{
	int		num2;
	char	c;

	c = ft_stack_op_pop(op);
	num2 = ft_stack_nbr_pop(num);
	if (c == '+')
		(*num)->nbr = (*num)->nbr + num2;
	if (c == '-')
		(*num)->nbr = (*num)->nbr - num2;
	if (c == '/')
		(*num)->nbr = (*num)->nbr / num2;
	if (c == '*')
		(*num)->nbr = (*num)->nbr * num2;
	if (c == '%')
		(*num)->nbr = (*num)->nbr % num2;
}

int		eval_expr(char *str)
{
	t_stack_nbr	*nbr_s;
	t_stack_op	*op_s;

	nbr_s = NULL;
	op_s = NULL;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			ft_stack_nbr_push(&nbr_s, ft_atoi(str));
			while (*str >= '0' && *str <= '9')
				str++;
		}
		else if (*str == '/' || *str == '*' || *str == '%' || *str == '(' ||
			*str == '+' || *str == '-')
		{
			if (ft_check_stack(op_s, *str))
			{
				ft_stack_op_push(&op_s, *str);
				str++;
			}
			else
			{
				ft_calc(&nbr_s, &op_s);
			}
		}
		else if (*str == ')')
		{
			while (op_s->op != '(')
			{
				ft_calc(&nbr_s, &op_s);
			}
			ft_stack_op_pop(&op_s);
			str++;
		}
		else
			str++;
	}
	while (nbr_s->next)
	{
		ft_calc(&nbr_s, &op_s);
	}
	printf("%d", nbr_s->nbr);
	return (0);
}

int		main(int argc, char **argv)
{
	argc = 0;
	eval_expr(argv[1]);
	return (0);
}
