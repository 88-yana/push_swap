/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 22:43:35 by hyanagim          #+#    #+#             */
/*   Updated: 2022/12/04 11:42:12 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/list.h"

static void	make_ring(t_lst *lst)
{
	(*lst).prev = lstlast(lst);
	lstlast(lst)->next = lst;
}

t_stack	*make_list(t_vars *vars)
{
	int		i;
	t_stack	*stack;
	t_lst	*temp;

	stack = malloc(sizeof(t_stack));
	stack->a = lstnew(-1);
	stack->b = lstnew(-1);
	if (stack == NULL || stack->a == NULL || stack->b == NULL)
		malloc_error();
	i = 0;
	while (i < vars->size)
	{
		temp = lstnew(vars->elements[i]);
		if (temp == NULL)
			malloc_error();
		lstadd_back(&(stack->a), temp);
		i++;
	}
	make_ring(stack->a);
	make_ring(stack->b);
	free(vars->elements);
	return (stack);
}

// int	main(int argc, char **argv)
// {
// 	t_lst	*a;
// 	t_lst	*b;

// 	a = lstnew(-1);
// 	b = lstnew(-1);

// 	int i = 1;
// 	while (i < 5)
// 	{
// 		t_lst *temp;
// 		temp = lstnew(ft_atoi(argv[i]));
// 		lstadd_back(&a, temp);
// 		i++;
// 	}
// 	make_ring(a);
// 	make_ring(b);
// 	i = 0;
// 	while (i < 9)
// 	{
// 		perform_task(sa, a, b, NOWRITE);
// 		perform_task(sb, a, b, NOWRITE);
// 		perform_task(pa, a, b, NOWRITE);
// 		perform_task(pb, a, b, NOWRITE);
// 		perform_task(ss, a, b, NOWRITE);
// 		perform_task(ra, a, b, NOWRITE);
// 		perform_task(rb, a, b, NOWRITE);
// 		perform_task(rr, a, b, NOWRITE);
// 		perform_task(rra, a, b, NOWRITE);
// 		perform_task(rrb, a, b, NOWRITE);
// 		perform_task(rrr, a, b, NOWRITE);
// 		i++;
// 	}
// 	show_list(a);
// 	show_list(b);
// 	return (0);
// }