/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 22:43:35 by hyanagim          #+#    #+#             */
/*   Updated: 2022/10/20 21:13:28 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/list.h"

static void	make_ring(t_lst *lst)
{
	(*lst).prev = lstlast(lst);
	lstlast(lst)->next = lst;
}

<<<<<<< HEAD
	a = lstnew(0);
	b = lstnew(0);
	if (a == NULL || b == NULL)
	{
		print_error("malloc failed");
		// system("leaks -q push_swap");
		exit (1);
	}
=======
t_stack	*make_list(t_vars *vars)
{
	long long	i;
	t_stack		*stack;
	t_lst		*temp;

	stack = malloc(sizeof(t_stack));
	stack->a = lstnew(0);
	stack->b = lstnew(0);
	if (stack == NULL || stack->a == NULL || stack->b == NULL)
		malloc_error();
>>>>>>> 50d42fa8070d0a19fa92135fe304113a1a17aaac
	i = 0;
	while (i < vars->size)
	{
		temp = lstnew(vars->elements[i]);
<<<<<<< HEAD
		// if (i == 1)
			// temp = NULL;
=======
>>>>>>> 50d42fa8070d0a19fa92135fe304113a1a17aaac
		if (temp == NULL)
			malloc_error();
		lstadd_back(&(stack->a), temp);
		i++;
	}
<<<<<<< HEAD
	(*a).prev = lstlast(a);
	lstlast(a)->next = a;
	(*b).prev = lstlast(b);
	lstlast(b)->next = b;
	show_list_r(a->prev, a);
=======
	make_ring(stack->a);
	make_ring(stack->b);
	free(vars->elements);
	return (stack);
>>>>>>> 50d42fa8070d0a19fa92135fe304113a1a17aaac
}
