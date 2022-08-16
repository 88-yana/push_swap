/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 00:01:12 by hyanagim          #+#    #+#             */
/*   Updated: 2022/08/17 08:22:48 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>

typedef struct s_list
{
	long			num;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(int num)
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

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		new->prev = ft_lstlast(*lst);
		new->prev->next = new;
	}
}

void	ft_show_list(t_list *lst, t_list *nil)
{
	while (lst != nil)
	{
		printf("%ld ", lst->num);
		lst = lst->next;
	}
}

void	ft_show_list_rr(t_list *lst, t_list *nil)
{
	int	cnt;

	cnt = 0;
	while (cnt != 3)
	{
		if (lst != nil)
			printf("%ld ", lst->num);
		lst = lst->prev;
		if (lst == nil)
			cnt++;
	}
}

// int	main(int argc, char **argv)
// {
// 	for (int i = 1; i < argc; i++)
// 		printf("%d : %s\n", i, argv[i]);

// 	t_list	*lst;
// 	lst = NULL;
// 	for (int i = 1; i < argc; i++)
// 	{
// 		ft_lstadd_back(&lst, ft_lstnew(atoi(argv[i])));
// 	}
// 	lst->prev = NULL;
// 	ft_show_list(lst);
// 	t_list	temp;
// 	temp = *lst;
// 	for (int i = 1; i < argc; i++)
// 	{
// 		printf("%d, %ld\n", i, temp.num);
// 		temp = *temp.next;
// 		printf("LINE == %d, FILE == %s\n", __LINE__, __FILE__);
// 	}
// 		printf("LINE == %d, FILE == %s\n", __LINE__, __FILE__);

// 	return 0;
// }

typedef enum enm {
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr,
}	t_instruction;

void	execute_ra(t_list *nil)
{
	nil->prev->next = nil->next;
	nil->next = nil->next->next;
	
}

void	execute_instr(t_instruction instr, t_list *a, t_list *b)
{
	// if (instr == sa)
	// 	return 
	if (instr == ra)
		return execute_ra(a);
}

int	main(int argc, char **argv)
{
	t_list	node;
	t_list	*nil;

	node = *ft_lstnew(0);
	nil = &node;
	for (int i = 1; i < argc; i++)
		ft_lstadd_back(&nil, ft_lstnew(atoi(argv[i])));
	node.prev = ft_lstlast(&node);
	ft_lstlast(&node)->next = nil;
	ft_show_list(nil->next, nil);
	ft_show_list_rr(nil->prev, nil);
	
	//t_instruction instr;
	return 0;
}

//mallocしたら，freeしなきゃいけない