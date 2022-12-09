/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:01:45 by hyanagim          #+#    #+#             */
/*   Updated: 2022/12/04 09:35:06 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/malloc.h"

void	free_array_char(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static int	arraylen(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

static void	insert_elements(t_vars *vars, char **array, int i)
{
	if (i == 0)
	{
		while (array[i])
		{
			vars->elements[i] = ft_atoi(array[i]);
			vars->twin[i] = ft_atoi(array[i]);
			i++;
		}
	}
	else
	{
		while (array[i])
		{
			vars->elements[i - 1] = ft_atoi(array[i]);
			vars->twin[i - 1] = ft_atoi(array[i]);
			i++;
		}
	}
}

void	make_array(t_vars *vars, int argc, char **argv)
{
	char	**array;

	array = NULL;
	vars->size = argc - 1;
	if (argc == 2)
	{
		array = ft_split(argv[1], ' ');
		if (array == NULL)
			malloc_error();
		vars->size = arraylen(array);
	}
	vars->elements = malloc(sizeof(int) * (vars->size));
	vars->twin = malloc(sizeof(int) * (vars->size));
	if (vars->elements == NULL || vars->twin == NULL)
		malloc_error();
	if (argc == 2)
		insert_elements(vars, array, 0);
	else
		insert_elements(vars, argv, 1);
	if (array != NULL)
	free_array_char(array);
	//freeする。
}
