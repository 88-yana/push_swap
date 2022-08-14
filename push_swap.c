/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 00:01:12 by hyanagim          #+#    #+#             */
/*   Updated: 2022/08/15 06:58:44 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>

typedef struct s_list
{
	int				*num;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *num)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->num = num;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

int	main(int argc, char **argv)
{
	for (int i = 0; i < argc; i++)
		printf("%d : %s\n", i, argv[i]);
	for (int i = 0; i < argc; i++)
	{
		ft_lstnew(atoi(argv[i]));
	}
	return 0;
}
