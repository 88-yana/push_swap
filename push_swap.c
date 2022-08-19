/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 00:01:12 by hyanagim          #+#    #+#             */
/*   Updated: 2022/08/19 09:52:54 by hyanagim         ###   ########.fr       */
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
}	t_task;

void	perform_r(t_list *nil)
{
	t_list *temp;

	nil->prev->next = nil->next;
	nil->next->next->prev = nil;
	nil->next->prev = nil->prev;
	temp = nil->next->next;
	nil->next->next = nil;
	nil->prev = nil->next;
	nil->next = temp;
}

void	perform_rr(t_list *nil)
{
	t_list *temp;

	nil->prev->prev->next = nil;
	nil->next->prev = nil->prev;
	temp = nil->prev->prev;
	nil->prev->prev = nil;
	nil->prev->next = nil->next;
	nil->next = nil->prev;
	nil->prev = temp;
}

void	perform_swap(t_task task, t_list *a, t_list *b)
{
	// if (task == sa)
	// 	perform_s(a);
	// if (task == sb)
	// 	perform_s(b);
	// if (task == ss)
	// {
	// 	perform_s(a);
	// 	perform_s(b);
	// }
}

void	perform_push(t_task task, t_list *a, t_list *b)
{
	// if (task == pa)
	// 	perform_p(a, b);
	// if (task == pb)
	// 	perform_p(b, a);
}

void	perform_rotate(t_task task, t_list *a, t_list *b)
{
	if (task == ra)
		perform_r(a);
	if (task == rb)
		perform_r(b);
	if (task == rr)
	{
		perform_r(a);
		perform_r(b);
	}
}

void	perform_reverse_rotate(t_task task, t_list *a, t_list *b)
{
	if (task == rra)
		perform_rr(a);
	if (task == rrb)
		perform_rr(b);
	if (task == rrr)
	{
		perform_rr(a);
		perform_rr(b);
	}
}

void	perform_task(t_task task, t_list *a, t_list *b)
{
	if (task == sa || task == sb || task == ss)
		perform_swap(task, a, b);
	if (task == pa || task == pb)
		perform_push(task, a, b);
	if (task == ra || task == rb || task == rr)
		perform_rotate(task, a, b);
	if (task == rra || task == rrb || task == rrr)
		perform_reverse_rotate(task, a, b);
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
	printf("\n");
	ft_show_list_rr(nil->prev, nil);
	printf("\n");
	printf("%ld\n", nil->num);
	printf("%ld\n", (*(nil->prev)).num);
	printf("%ld\n", nil->prev->num);
	//t_task task;
	perform_task(ra, nil, nil);
	printf("show list : ");
	ft_show_list(nil->next, nil);
	printf("\n");
	printf("show r list : ");
	ft_show_list_rr(nil->prev, nil);
	printf("\n");
	printf("%ld\n", nil->num);
	printf("%ld\n", (*(nil->prev)).num);
	printf("%ld\n", nil->prev->num);
	perform_task(rra, nil, nil);
	printf("show list : ");
	ft_show_list(nil->next, nil);
	printf("\n");
	printf("show r list : ");
	ft_show_list_rr(nil->prev, nil);
	printf("\n");
	printf("%ld\n", nil->num);
	printf("%ld\n", (*(nil->prev)).num);
	printf("%ld\n", nil->prev->num);
	perform_task(rra, nil, nil);
	printf("show list : ");
	ft_show_list(nil->next, nil);
	printf("\n");
	printf("show r list : ");
	ft_show_list_rr(nil->prev, nil);
	printf("\n");
	printf("%ld\n", nil->num);
	printf("%ld\n", (*(nil->prev)).num);
	printf("%ld\n", nil->prev->num);
	return 0;
}

//mallocしたら，freeしなきゃいけない