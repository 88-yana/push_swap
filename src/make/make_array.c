/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:01:45 by hyanagim          #+#    #+#             */
/*   Updated: 2022/10/25 13:02:10 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/malloc.h"

void	make_array(t_vars *vars, int argc, char **argv)
{
	int	i;

	vars->size = argc - 1;
	vars->elements = malloc(sizeof(int) * (vars->size));
	vars->twin = malloc(sizeof(int) * (vars->size));
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
