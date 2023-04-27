/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:22:26 by bmetehri          #+#    #+#             */
/*   Updated: 2023/04/27 11:38:04 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		new_line_founded(t_list *mylist)
{
	int	i;
	t_list	*current;

	if (mylist == NULL)
		return (0);
	current = ft_lst_get_last(mylist);
	i = 0;
	while (current->content[i])
	{
		if (current->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_list	*ft_lst_get_last(t_list *mylist)
{
	t_list	*current;

	current = mylist;
	// printf("Avant le memory leak\n");
	while (current && current->next)
		current = current->next;
	return (current);
}

void	allocate_memory_to_line(char **line, t_list *mylist)
{
	int	i;
	int	len;

	len = 0;
	while (mylist)
	{
		i = 0;
		while (mylist->content[i])
		{
			if (mylist->content[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		mylist = mylist->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
}

int	ft_strlen(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	free_list(t_list *mylist)
{
	t_list	*current;
	t_list	*next;

	current = mylist;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}
