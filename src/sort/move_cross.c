/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cross.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:21:09 by hyanagim          #+#    #+#             */
/*   Updated: 2022/10/28 18:22:23 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/sort.h"

static void	cross_sub(t_lst *lst[5], int quate[2], bool *is_esc, int data[2])
{
	lst[BEFORE] = lst[MAIN]->next;
	perform_task(pb, lst[MAIN], lst[SUB], data[TYPE]);
	if (is_correspond(lst[MAIN]->next->num, quate[0], data[INDEX]))
		return (perform_task(rb, lst[MAIN], lst[SUB], data[TYPE]));
	if (is_correspond(lst[MAIN]->next->num, quate[1], data[INDEX]))
		return (perform_task(rb, lst[MAIN], lst[SUB], data[TYPE]));
	if (lst[MAIN]->next == lst[FIRST] || lst[LAST] == lst[BEFORE])
		return (perform_task(rb, lst[MAIN], lst[SUB], data[TYPE]));
	if (lst[MAIN]->next == lst[LAST])
		*is_esc = true;
	perform_task(rr, lst[MAIN], lst[SUB], data[TYPE]);
}

void	move_cross(t_stack *stack, int quaternary[2], int index, int type)
{
	t_lst	*lst[5];
	bool	is_escape;
	int		data[2];

	lst[MAIN] = set_lst(stack, stack->a, type);
	lst[SUB] = set_lst(stack, stack->b, type);
	lst[FIRST] = lst[MAIN]->next;
	lst[LAST] = lst[MAIN]->prev;
	data[INDEX] = index;
	data[TYPE] = type;
	is_escape = false;
	while (1)
	{
		if (is_correspond(lst[MAIN]->next->num, quaternary[0], index))
			perform_task(pb, lst[MAIN], lst[SUB], type);
		else if (is_correspond(lst[MAIN]->next->num, quaternary[1], index))
			cross_sub(lst, quaternary, &is_escape, data);
		else
			perform_task(ra, lst[MAIN], lst[SUB], type);
		if (is_escape || lst[MAIN] == lst[MAIN]->next)
			break ;
		if (lst[MAIN]->next == lst[LAST])
			is_escape = true;
	}
}

void	move_cross_back(t_stack *stack, int quaternary, int index, int type)
{
	t_lst	*main;
	t_lst	*sub;

	main = set_lst(stack, stack->a, type);
	sub = set_lst(stack, stack->b, type);
	while (is_correspond(main->prev->num, quaternary, index))
	{
		perform_task(rra, main, sub, type);
		perform_task(pb, main, sub, type);
	}
}
