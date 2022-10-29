/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srot_revised.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:44:46 by hyanagim          #+#    #+#             */
/*   Updated: 2022/10/28 18:27:30 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/sort.h"

// void	print_stack(t_stack *stack)
// {
// 	ft_printf("stack a : ");
// 	show_list(stack->a);
// 	ft_printf("stack b : ");
// 	show_list(stack->b);
// }

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
	exp = cnt_sort(vars->size);
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
