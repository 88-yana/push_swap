/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 22:45:30 by hyanagim          #+#    #+#             */
/*   Updated: 2022/10/13 23:16:04 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_lst	*a;
	t_lst	*b;

	a = NULL;
	b = NULL;
	check_arg(argc, argv);
	make_array(&vars, argc, argv);
	check_duplicate(&vars);
	check_sorted(&vars);
	shrink_array(&vars);
	make_list(&vars, a, b);
	// sort(&vars);
	return (0);
}
