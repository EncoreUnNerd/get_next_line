/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:32:21 by mhenin            #+#    #+#             */
/*   Updated: 2024/10/31 11:32:23 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

struct s_stock	*create_node(char	*value)
{
	struct s_stock	*node;
	int				i;

	i = 0;
	node = malloc(sizeof(struct s_stock));
	while (value[i])
	{
		node->value[i] = value[i];
		i++;
	}
	node->value[i] = '\0';
	node->next = NULL;
	return (node);
}

void	add_back(char	*value, struct s_stock **head)
{
	struct s_stock	*new_node;
	struct s_stock	*current;

	new_node = create_node(value);
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
}

void	pop_front(struct s_stock **head)
{
	struct s_stock	*temp;

	if (*head == NULL)
		return ;
	temp = *head;
	*head = (*head)->next;
	free(temp);
}

int	check_if_endline(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	clean_to_endline(struct s_stock **head)
{
	int		i;
	int		l;

	i = 0;
	l = 0;
	while (*head != NULL)
	{
		if (check_if_endline((*head)->value))
		{
			while ((*head)->value[i] != '\n')
				i++;
			while ((*head)->value[++i])
				(*head)->value[l++] = (*head)->value[i];
			break ;
		}
		else
			pop_front(&(*head));
	}
}

char	*get_line(struct s_stock *head)
{
	struct s_stock	*current;
	char			*res;
	int				i;
	int				len;

	current = head;
	i = 0;
	len = 0;
	while (current != NULL)
	{
		while (current->value[i] && current->value[i] != '\n')
		{
			len++;
			i++;
		}
		if (current->value[i] == '\n')
			break ;
		i = 0;
		current = current->next;
	}
	res = malloc(sizeof(char) * (len + 2));
	current = head;
	len = 0;
	i = 0;
	while (current != NULL)
	{
		while (current->value[i] && current->value[i] != '\n')
		{
			res[len] = current->value[i];
			len++;
			i++;
		}
		if (current->value[i] == '\n')
		{
			res[len++] = '\n';
			break ;
		}
		i = 0;
		current = current->next;
	}
	res[len] = '\0';
	return (res);
}
