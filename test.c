#include "get_next_line.h"
#include <stdlib.h>

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

struct stock *create_node(char	*value)
{
	struct stock	*node;

	node = malloc(sizeof(struct stock));
	node->value = ft_strdup(value);
	node->next = NULL;
	return (node);
}

void add_back(char	*value, struct stock **head)
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

int main(void)
{
	struct stock	*stock;
	add_back("je test", &stock);
	add_back("je test 2 ", &stock);
	add_back("je test3 ", &stock);
}
// test
