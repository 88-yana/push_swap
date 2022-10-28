/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srot_revised.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:44:46 by hyanagim          #+#    #+#             */
/*   Updated: 2022/10/28 18:18:59 by hyanagim         ###   ########.fr       */
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

void	move_cross_sub(t_lst *lst[5], int quate[2], bool *is_esc, int data[2])
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
			move_cross_sub(lst, quaternary, &is_escape, data);
		else
			perform_task(ra, lst[MAIN], lst[SUB], type);
		if (is_escape || lst[MAIN] == lst[MAIN]->next)
			break ;
		if (lst[MAIN]->next == lst[LAST])
			is_escape = true;
	}
}

// void	move_cross(t_stack *stack, int quaternary[2], int index, int type)
// {
// 	t_lst	*main;
// 	t_lst	*sub;
// 	t_lst	*last;
// 	t_lst	*first;
// 	t_lst	*before;
// 	bool	is_escape;

// 	main = set_lst(stack, stack->a, type);
// 	sub = set_lst(stack, stack->b, type);
// 	first = main->next;
// 	last = main->prev;
// 	is_escape = false;
// 	while (1)
// 	{
// 		if (is_correspond(main->next->num, quaternary[0], index))
// 			perform_task(pb, main, sub, type);
// 		else if (is_correspond(main->next->num, quaternary[1], index))
// 		{
// 			before = main->next;
// 			perform_task(pb, main, sub, type);
// 			if (!is_correspond(main->next->num, quaternary[0], index) && !is_correspond(main->next->num, quaternary[1], index) && main->next != first && last != before)
// 			{
// 				if (main->next == last)
// 					is_escape = true;
// 				perform_task(rr, main, sub, type);
// 			}
// 			else
// 				perform_task(rb, main, sub, type);
// 		}
// 		else
// 			perform_task(ra, main, sub, type);
// 		if (is_escape || main == main->next)
// 			break ;
// 		if (main->next == last)
// 			is_escape = true;
// 	}
// }

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
	transfer_elements(stack, 10, index, ATOB);
}

int	power(int x, int exp)
{
	while (--exp)
		x *= 2;
	return (x);
}

int	cntsort(int size)
{
	int	exp;

	exp = 0;
	while (1)
	{
		exp++;
		if (power(2, exp) < size && size <= power(2, exp + 1))
			break ;
	}
	return (exp);
}

void	sort_by_binary(t_stack *stack, int index)
{
	transfer_elements(stack, 00, index, ATOB);
	transfer_elements(stack, 01, index, BTOA);
}

void	sort(t_stack *stack, t_vars *vars)
{
	int	index;
	int	quaternary[2];
	int	i;
	int	exp;

	index = 0;
	i = 0;
	exp = cntsort(vars->size);
	first_divide_into_four(stack);
	while (i < (exp - 1) / 2)
	{
		index += 2;
		leave_elements(stack, 11, index, ATOB);
		quaternary[0] = 11;
		quaternary[1] = 01;
		move_cross(stack, quaternary, index, BTOA);
		transfer_elements(stack, 10, index, BTOA);
		move_cross_back(stack, 01, index, ATOB);
		i++;
	}
	if (exp % 2 == 0)
		sort_by_binary(stack, index + 2);
	move_all(stack, BTOA);
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
