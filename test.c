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
	char	*s2;
	char	*new;
	int		i;

	s2 = (char *)s1;
	i = 0;
	new = (char *)malloc(sizeof(char) * ft_strlen(s2) + 1);
	if (new == NULL)
		return (NULL);
	while (s2[i])
	{
		new[i] = s2[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;

	i = 0;
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s3 == NULL)
		return (NULL);
	j = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j])
		s3[i++] = s2[j++];
	s3[i] = '\0';
	return (s3);
}


int main()
{
	char	*te;

	te = NULL;
	te = ft_strjoin(te, "1cacaboudin");
	te = ft_strjoin(te, "cacaboudin");
	te = ft_strjoin(te, "cacaboudin");
	te = ft_strjoin(te, "cacabo\tudin");
	te = ft_strjoin(te, "cacaboudin");
	te = ft_strjoin(te, "cacaboudin");
	te = ft_strjoin(te, "cacab\noudin");
	printf("%s", te);
	free(te);
}
