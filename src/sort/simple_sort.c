/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:26:15 by hyanagim          #+#    #+#             */
/*   Updated: 2022/12/11 08:24:58 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/sort.h"

static t_task	reverse_task(t_task task)
{
	if (task == pa)
		return (pb);
	else if (task == pb)
		return (pa);
	else if (task == ra)
		return (rra);
	else if (task == rra)
		return (ra);
	else if (task == rb)
		return (rrb);
	else if (task == rrb)
		return (rb);
	else if (task == rr)
		return (rrr);
	else if (task == rrr)
		return (rr);
	else
		return (task);
}

static void	print_task(t_task task)
{
	if (task == pa)
		ft_printf("pa\n");
	else if (task == pb)
		ft_printf("pb\n");
	else if (task == ra)
		ft_printf("ra\n");
	else if (task == rra)
		ft_printf("rra\n");
	else if (task == rb)
		ft_printf("rb\n");
	else if (task == rrb)
		ft_printf("rrb\n");
	else if (task == rr)
		ft_printf("rr\n");
	else if (task == rrr)
		ft_printf("rrr\n");
	else if (task == sa)
		ft_printf("sa\n");
	else if (task == sb)
		ft_printf("sb\n");
	else if (task == ss)
		ft_printf("ss\n");
}

static void	update_operations(t_vars *vars, int turn)
{
	int	i;

	vars->max_turn = turn;
	i = 0;
	while (i < vars->max_turn)
	{
		vars->task[i] = vars->task_sub[i];
		i++;
	}
	vars->task[i] = null;
}

static void	greedy(t_stack *stack, t_vars *vars, t_task prev_task, int turn)
{
	t_task	task;
	int		prev_a;
	int		prev_b;

	if (turn >= vars->max_turn)
		return ;
	if (lstlen(stack->a) == vars->size && is_sorted(stack->a))
	{
		update_operations(vars, turn);
		return ;
	}
	task = null;
	while (++task <= rrr)
	{
		if (prev_task == reverse_task(task))
			continue ;
		prev_a = stack->a->next->num;
		prev_b = stack->b->next->num;
		perform_task(task, stack->a, stack->b, NOWRITE);
		if (prev_a == stack->a->next->num && prev_b == stack->b->next->num)
			continue ;
		vars->task_sub[turn] = task;
		greedy(stack, vars, task, turn + 1);
		perform_task(reverse_task(task), stack->a, stack->b, NOWRITE);
	}
}

void	simple_sort(t_stack *stack, t_vars *vars)
{
	int	i;

	vars->max_turn = 9;
	greedy(stack, vars, null, 0);
	i = 0;
	while (vars->task[i] != null)
	{
		print_task(vars->task[i]);
		i++;
	}
	exit (0);
}
