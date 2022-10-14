/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 22:45:30 by hyanagim          #+#    #+#             */
/*   Updated: 2022/10/14 18:24:14 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_stack	*stack;

	check_arg(argc, argv);
	make_array(&vars, argc, argv);
	check_duplicate(&vars);
	check_sorted(&vars);
	shrink_array(&vars);
	stack = make_list(&vars);
	// show_list(stack->a);
	// show_list_r(stack->a);
	sort(stack, &vars);
	greedy(stack);
	// show_list(stack->a);
	// show_list(stack->b);
	// system("leaks -q push_swap");
	return (0);
}
