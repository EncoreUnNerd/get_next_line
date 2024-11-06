#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (new == NULL)
		return (NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	char	*s3;
	int		i;
	int		j;

	i = 0;
	if (s1 == NULL)
		return (ft_strdup(s2));
	s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s3 == NULL)
	{
		free(s1);
		return (NULL);
	}
	j = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j])
		s3[i++] = s2[j++];
	s3[i] = '\0';
	free(s1);
	return (s3);
}

char	*clear(char *str)
{
	int		i;
	char	*res;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] != '\0')
		{
			res = ft_strdup(&str[i + 1]);
			free(str);
			return (res);
		}
		i++;
	}
	return (NULL);
}

char	*ft_get_line(char	*str)
{
	char	*res;
	int		i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		i++;
	res = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		res[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		res[i++] = '\n';
	res[i] = '\0';
	return (res);
}

int	main(void)
{
	char	*te;
	char	*res;

	te = NULL;
	te = ft_strjoin(te, "1cacaboudin");
	te = ft_strjoin(te, "cacaboudin");
	te = ft_strjoin(te, "cacaboudin");
	te = ft_strjoin(te, "cacabo\tudin");
	te = ft_strjoin(te, "cacaboudin");
	te = ft_strjoin(te, "cacaboudin");
	te = ft_strjoin(te, "cacab");
	res = ft_get_line(te);
	printf("%s-1", res);
	te = clear(te);
	printf("%s-2", te);
	free(te);
	return (0);
}
