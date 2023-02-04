/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 06:24:02 by bmetehri          #+#    #+#             */
/*   Updated: 2023/02/04 08:36:03 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(char content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*list;

	if (!(*lst))
		*lst = new;
	else
	{
		list = *lst;
		while (list->next)
			list = list->next;
		list->next = new;
	}
}

int		ft_lstclear(t_list **lst)
{
	t_list	*temp;

	while ((*lst))
	{
		temp = *lst;
		(*lst) = (*lst)->next;
		free(temp);
		temp = NULL;
	}
	return (0);
}
