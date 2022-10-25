/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srot_revised.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:44:46 by hyanagim          #+#    #+#             */
/*   Updated: 2022/10/25 20:54:06 by hyanagim         ###   ########.fr       */
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

void	move_cross(t_stack *stack, int quaternary[2], int index, int type)
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
		if (is_correspond(main->next->num, quaternary[0], index))
			perform_task(pb, main, sub, type);
		else if (is_correspond(main->next->num, quaternary[1], index))
		{
			perform_task(pb, main, sub, type);
			perform_task(rb, main, sub, type);
		}
		else
			perform_task(ra, main, sub, type);
		if (is_escape || main == main->next)
			break ;
		if (main->next == last)
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

void	print_stack(t_stack *stack)
{
	ft_printf("stack a : ");
	show_list(stack->a);
	ft_printf("stack b : ");
	show_list(stack->b);
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

void	sort(t_stack *stack, t_vars *vars)
{
	int	index;
	int	quaternary[2];

	index = 0;
	quaternary[0] = 01;
	quaternary[1] = 00;
	move_cross(stack, quaternary, index, ATOB);
	// print_stack(stack);
	transfer_elements(stack, 10, index, ATOB);
	// print_stack(stack);
	index += 2;
	leave_elements(stack, 11, index, ATOB);
	// print_stack(stack);
	quaternary[0] = 11;
	quaternary[1] = 01;
	move_cross(stack, quaternary, index, BTOA);
	// print_stack(stack);
	transfer_elements(stack, 10, index, BTOA);
	// print_stack(stack);
	move_cross_back(stack, 01, index, ATOB);

	index += 2;
	leave_elements(stack, 11, index, ATOB);
	// print_stack(stack);
	quaternary[0] = 11;
	quaternary[1] = 01;
	move_cross(stack, quaternary, index, BTOA);
	// print_stack(stack);
	transfer_elements(stack, 10, index, BTOA);
	// print_stack(stack);
	move_cross_back(stack, 01, index, ATOB);
	index += 2;
	leave_elements(stack, 11, index, ATOB);
	// print_stack(stack);
	quaternary[0] = 11;
	quaternary[1] = 01;
	move_cross(stack, quaternary, index, BTOA);
	// print_stack(stack);
	transfer_elements(stack, 10, index, BTOA);
	// print_stack(stack);
	move_cross_back(stack, 01, index, ATOB);
	index += 2;
	transfer_elements(stack, 00, index, ATOB);
	transfer_elements(stack, 01, index, BTOA);
	// index += 2;
	// leave_elements(stack, 11, index, ATOB);
	// // print_stack(stack);
	// quaternary[0] = 11;
	// quaternary[1] = 01;
	// move_cross(stack, quaternary, index, BTOA);
	// // print_stack(stack);
	// transfer_elements(stack, 10, index, BTOA);
	// // print_stack(stack);
	// move_cross_back(stack, 01, index, ATOB);
	// index += 2;
	// leave_elements(stack, 11, index, ATOB);
	// // print_stack(stack);
	// quaternary[0] = 11;
	// quaternary[1] = 01;
	// move_cross(stack, quaternary, index, BTOA);
	// // print_stack(stack);
	// transfer_elements(stack, 10, index, BTOA);
	// // print_stack(stack);
	// move_cross_back(stack, 01, index, ATOB);
	move_all(stack, BTOA);
	// leave_elements(stack, 11, index, ATOB);
	// print_stack(stack);
	// ft_printf("stack a : ");
	// show_list(stack->a);
	// ft_printf("stack b : ");
	// show_list(stack->b);
	(void) vars;
}
