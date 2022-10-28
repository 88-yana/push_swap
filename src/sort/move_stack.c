/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:23:28 by hyanagim          #+#    #+#             */
/*   Updated: 2022/10/28 18:23:59 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/sort.h"

t_lst	*set_lst(t_stack *stack, t_lst *lst, int type)
{
	if (type == ATOB)
		return (lst);
	if (stack->a == lst)
		return (stack->b);
	return (stack->a);
}

void	transfer_elements(t_stack *stack, int quaternary, int index, int type)
{
	t_lst	*main;
	t_lst	*sub;
	t_lst	*last;
	bool	is_escape;

	main = set_lst(stack, stack->a, type);
	sub = set_lst(stack, stack->b, type);
	last = main->prev;
	is_escape = false;
	while (1)
	{
		if (is_correspond(main->next->num, quaternary, index))
			perform_task(pb, main, sub, type);
		else
			perform_task(ra, main, sub, type);
		if (is_escape || main == main->next)
			break ;
		if (main->next == last)
			is_escape = true;
	}
}

void	leave_elements(t_stack *stack, int quaternary, int index, int type)
{
	t_lst	*main;
	t_lst	*sub;
	t_lst	*last;
	bool	is_escape;

	main = set_lst(stack, stack->a, type);
	sub = set_lst(stack, stack->b, type);
	last = main->prev;
	is_escape = false;
	while (1)
	{
		if (is_correspond(main->next->num, quaternary, index))
			perform_task(ra, main, sub, type);
		else
			perform_task(pb, main, sub, type);
		if (is_escape || main == main->next)
			break ;
		if (main->next == last)
			is_escape = true;
	}
}

void	move_all(t_stack *stack, int type)
{
	t_lst	*main;
	t_lst	*sub;
	t_lst	*last;
	bool	is_escape;

	main = set_lst(stack, stack->a, type);
	sub = set_lst(stack, stack->b, type);
	last = main->prev;
	is_escape = false;
	while (1)
	{
		perform_task(pb, main, sub, type);
		if (is_escape || main == main->next)
			break ;
		if (main->next == last)
			is_escape = true;
	}
}
