/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 22:21:01 by hyanagim          #+#    #+#             */
/*   Updated: 2022/12/11 08:56:26 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/list.h"

t_lst	*lstnew(int num)
{
	t_lst	*new;

	new = malloc(sizeof(t_lst));
	if (new == NULL)
		return (NULL);
	new->num = num;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

t_lst	*lstlast(t_lst *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	lstadd_back(t_lst **lst, t_lst *new)
{
	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		new->prev = lstlast(*lst);
		new->prev->next = new;
	}
}

int	lstlen(t_lst *lst)
{
	int		size;
	t_lst	*nil;

	size = 0;
	nil = lst;
	lst = lst->next;
	while (lst != nil)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}
