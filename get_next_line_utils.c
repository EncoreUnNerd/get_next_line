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

char	*ft_strdup(const char *src)
{
	char	*res;
	int		src_len;
	size_t	i;

	src_len = 0;
	while (src[src_len])
		src_len++;
	res = (char *)malloc(sizeof(char) * (src_len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (src[i])
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

struct stock	*create_node(char	*value)
{
	struct stock	*node;

	node = malloc(sizeof(struct stock));
	node->value = ft_strdup(value);
	node->next = NULL;
	return (node);
}

void	add_back(char	*value, struct stock **head)
{
	struct stock	*new_node;
	struct stock	*current;

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

void	pop_front(struct stock **head)
{
	struct stock	*temp;

	if (*head == NULL)
	{
		return ;
	}
	temp = *head;
	*head = (*head)->next;
	free(temp->value);
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

void	clean_to_endline(struct stock **head)
{
	int		i;

	i = 0;
	while (*head != NULL)
	{
		if (check_if_endline((*head)->value))
		{
			while ((*head)->value[i] != '\n')
				i++;
			(*head)->value = ft_strdup(&(*head)->value[++i]);
			break ;
		}
		else
			pop_front(&(*head));
	}
}

char	*get_line(struct stock *head)
{
	struct stock	*current;
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
