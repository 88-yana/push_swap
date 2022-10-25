/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srot_revised.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:44:46 by hyanagim          #+#    #+#             */
/*   Updated: 2022/10/25 14:17:04 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/sort.h"

void	transfer_elements(t_stack *stack, int quaternary, int index, int type)
{
	t_lst	*main;
	t_lst	*sub;
	t_lst	*last;
	bool	escape;

	main = stack->a;
	sub = stack->b;
	if (type == BTOA)
	{
		main = stack->b;
		sub = stack->a;
	}
	last = main->prev;
	escape = false;
	while (1)
	{
		if (is_correspond(main->next->num, quaternary, index))
			perform_task(pb, main, sub, type);
		else
			perform_task(ra, main, sub, type);
		if (escape)
			break ;
		if (main->next == last)
			escape = true;
	}
}

void	leave_elements(t_stack *stack, int quaternary, int index, int type)
{
	t_lst	*main;
	t_lst	*sub;
	t_lst	*last;
	bool	escape;

	main = stack->a;
	sub = stack->b;
	if (type == BTOA)
	{
		main = stack->b;
		sub = stack->a;
	}
	last = main->prev;
	escape = false;
	while (1)
	{
		if (is_correspond(main->next->num, quaternary, index))
			perform_task(ra, main, sub, type);
		else
			perform_task(pb, main, sub, type);
		if (escape)
			break ;
		if (main->next == last)
			escape = true;
	}
}

void	move_cross(t_stack *stack, int quaternary, int index, int type)
{
	t_lst	*main;
	t_lst	*sub;
	t_lst	*last;
	bool	escape;

	main = stack->a;
	sub = stack->b;
	if (type == BTOA)
	{
		main = stack->b;
		sub = stack->a;
	}
	last = main->prev;
	escape = false;
	while (1)
	{
		if (is_correspond(main->next->num, quaternary, index))
			perform_task(ra, main, sub, type);
		else
			perform_task(pb, main, sub, type);
		if (escape)
			break ;
		if (main->next == last)
			escape = true;
	}
}
