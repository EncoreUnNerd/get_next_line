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
#include <stdlib.h>

void	pop_front(struct s_stock **head)
{
	struct s_stock	*temp;

	if (*head == NULL)
		return ;
	temp = *head;
	*head = (*head)->next;
	free(temp);
}

void	clean_to_endline(struct s_stock **head)
{
	char	temp[BUFFER_SIZE + 1];
	int		i;
	int		l;

	if (!head || !*head)
		return;
	while (*head && !check_if_endline((*head)->value))
		pop_front(head);
	if (!*head)
		return;
	i = 0;
	l = 0;
	while (i < BUFFER_SIZE && (*head)->value[i] != '\n')
		i++;
	if ((*head)->value[i] == '\n')
		i++;
	while (i < BUFFER_SIZE && (*head)->value[i])
		temp[l++] = (*head)->value[i++];
	temp[l] = '\0';
	ft_memset((*head)->value, 0, BUFFER_SIZE);
	i = 0;
	while (temp[i] && i < BUFFER_SIZE)
	{
		(*head)->value[i] = temp[i];
		i++;
	}
}

int	opti(struct s_stock *current, char **res, int p)
{
	int	i;
	int	len;

	len = 0;
	while (current != NULL)
	{
		i = 0;
		while (i < BUFFER_SIZE && (current->value[i] != '\n')
			&& (current->value[i] != '\0'))
		{
			if (p == 1)
				(*res)[len] = current->value[i];
			len++;
			i++;
		}
		if (current->value[i] == '\n')
		{
			if (p == 1)
				(*res)[len++] = '\n';
			break ;
		}
		current = current->next;
	}
	return (len);
}

char	*gett_line(struct s_stock *head)
{
	char	*res;
	int		len;

	if (!head)
		return (NULL);
	len = opti(head, NULL, 0);
	if (len <= 0)
		return (NULL);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	opti(head, &res, 1);
	res[len] = '\0';
	return (res);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t		i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
		ptr[i++] = (unsigned char)c;
	return (s);
}
