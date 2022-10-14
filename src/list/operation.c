/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 22:21:56 by hyanagim          #+#    #+#             */
/*   Updated: 2022/10/14 14:56:47 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/list.h"

static void	perform_swap(t_task task, t_lst *a, t_lst *b)
{
	if (task == sa)
		perform_s(a);
	if (task == sb)
		perform_s(b);
	if (task == ss)
	{
		perform_s(a);
		perform_s(b);
	}
}

static void	perform_push(t_task task, t_lst *a, t_lst *b)
{
	if (task == pa)
		perform_p(b, a);
	if (task == pb)
		perform_p(a, b);
}

static void	perform_rotate(t_task task, t_lst *a, t_lst *b)
{
	if (task == ra)
		perform_r(a);
	if (task == rb)
		perform_r(b);
	if (task == rr)
	{
		perform_r(a);
		perform_r(b);
	}
}

static void	perform_reverse_rotate(t_task task, t_lst *a, t_lst *b)
{
	if (task == rra)
		perform_rr(a);
	if (task == rrb)
		perform_rr(b);
	if (task == rrr)
	{
		perform_rr(a);
		perform_rr(b);
	}
}

void	perform_task(t_task task, t_lst *a, t_lst *b)
{
	if (task == sa || task == sb || task == ss)
		perform_swap(task, a, b);
	if (task == pa || task == pb)
		perform_push(task, a, b);
	if (task == ra || task == rb || task == rr)
		perform_rotate(task, a, b);
	if (task == rra || task == rrb || task == rrr)
		perform_reverse_rotate(task, a, b);
}
