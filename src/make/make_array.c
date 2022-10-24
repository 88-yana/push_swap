/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:01:45 by hyanagim          #+#    #+#             */
/*   Updated: 2022/10/20 21:13:07 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/malloc.h"

void	make_array(t_vars *vars, long long argc, char **argv)
{
	long long	i;

	vars->size = argc - 1;
	vars->elements = malloc(sizeof(long long) * (vars->size));
	vars->twin = malloc(sizeof(long long) * (vars->size));
	if (vars->elements == NULL || vars->twin == NULL)
		malloc_error();
	i = 1;
	while (argv[i])
	{
		vars->elements[i - 1] = ft_atoi(argv[i]);
		vars->twin[i - 1] = ft_atoi(argv[i]);
		i++;
	}
}
