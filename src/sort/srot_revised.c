/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srot_revised.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:44:46 by hyanagim          #+#    #+#             */
/*   Updated: 2022/10/27 21:41:16 by hyanagim         ###   ########.fr       */
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
	t_lst	*first;
	t_lst	*before;
	bool	is_escape;

	main = set_lst(stack, stack->a, type);
	sub = set_lst(stack, stack->b, type);
	first = main->next;
	last = main->prev;
	is_escape = false;
	while (1)
	{
		if (is_correspond(main->next->num, quaternary[0], index))
			perform_task(pb, main, sub, type);
		else if (is_correspond(main->next->num, quaternary[1], index))
		{
			before = main->next;
			perform_task(pb, main, sub, type);
			if (!is_correspond(main->next->num, quaternary[0], index) && !is_correspond(main->next->num, quaternary[1], index) && main->next != first && last != before)
			{
				if (main->next == last)
					is_escape = true;
					perform_task(rr, main, sub, type);
			}
			else
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

// 6 12 15 14 10 1 4 16 13 8 2 3 9 11 5 7
// 10 3 14 13 11 9 7 12 16 6 4 8 1 15 2 5

//3 2 1 4
//2 3 1 4

void	first_divide_into_four(t_stack *stack)
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
}

int	cnt_sort(t_vars *vars)
{
	int	cnt;
	int	size;

	size = vars->size;
	size /= 2;
	cnt = 0;
	while (size > 0)
	{
		size /= 2;
		cnt++;
	}
	return (cnt);
}

int	power(int cnt_of_sort)
{
	int	ret;

	ret = 1;
	while (cnt_of_sort > 0)
	{
		ret *= 2;
		cnt_of_sort--;
	}
	return (ret);
}

void	sort(t_stack *stack, t_vars *vars)
{
	int	index;
	int	quaternary[2];
	int	cnt_of_sort;
	
	index = 0;
	// cnt_of_sort = cnt_sort(vars);
	// printf("cnt_of_sort %d\n", cnt_of_sort);
	// printf("max size %d\n", power(cnt_of_sort));
	// printf("amari %d\n", vars->size % power(cnt_of_sort));
	first_divide_into_four(stack);
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
	// print_stack(stack);
	// quaternary[0] = 11;
	// quaternary[1] = 01;
	// move_cross(stack, quaternary, index, BTOA);
	// print_stack(stack);
	// transfer_elements(stack, 10, index, BTOA);
	// print_stack(stack);
	// move_cross_back(stack, 01, index, ATOB);
	// index += 2;
	// leave_elements(stack, 11, index, ATOB);
	// print_stack(stack);
	// quaternary[0] = 11;
	// quaternary[1] = 01;
	// move_cross(stack, quaternary, index, BTOA);
	// print_stack(stack);
	// transfer_elements(stack, 10, index, BTOA);
	// print_stack(stack);
	// move_cross_back(stack, 01, index, ATOB);
	move_all(stack, BTOA);
	// print_stack(stack);
	// leave_elements(stack, 11, index, ATOB);
	// print_stack(stack);
	// ft_printf("stack a : ");
	// show_list(stack->a);
	// ft_printf("stack b : ");
	// show_list(stack->b);
	(void) vars;
}




/*
		2
		1
		0
		3

ra				ra
pb				pb
pb				pb
rr				rb
ra				ra
ra				pb
pb				ra
ra				pb
pb				rb
rb				rb
rb				rb
rb				rb
rb				rb
rb				rb
rb				rb
rb				rb
rb				pa
pa				pa
pa				pa
pa				pa
pa				
*/
