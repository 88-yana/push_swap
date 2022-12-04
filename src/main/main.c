/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 22:45:30 by hyanagim          #+#    #+#             */
/*   Updated: 2022/12/04 12:46:18 by hyanagim         ###   ########.fr       */
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
	if (vars.size < 6)
		simple_sort(stack, &vars);
	sort(stack, &vars);
	return (0);
}

