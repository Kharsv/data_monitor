#include "libft.h"
static char	*ft_strdup_c(char c, char *src)
{
	int		i;
	char	*s;

	i = 0;
	while (src[i] != c && src[i] != '\0')
		i++;
	s = malloc(sizeof(char) * (i + 1));
	if (s == NULL)
		return (NULL);
	if (s != 0)
	{
		i = 0;
		while (src[i] != c && src[i] != '\0')
		{
			s[i] = src[i];
			i++;
		}
		s[i] = '\0';
	}
	return (s);
}

static int	ft_count_c(const char *s1, char c)
{	
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		while (s1[i] == c)
			i++;
		if(s1[i] == '\0')
			return(j);
		while (s1[i] != c && s1[i] != '\0')
			i++;
		j++;
	}
	return (j);
}
static char	**ft_mem_fill_or_free(int k, char **array, char *start, char c)
{	
	array[k] = ft_strdup_c(c, start);
	if (array[k] == NULL)
		while (k > 0)
		{
			free((char *)array[k]);
			free((char **)array[k]);
			k--;
			return( NULL );
		}
	return (array);
}

char	**ft_split(const char *s1, char c)
{
	int		k;
	char	*start;
	char	**array;

	k = 0;
	array = malloc (sizeof(char *) * (ft_count_c(s1, c) + 1));
	if (!array)
		return (NULL);
	start = (char *)s1;
	while (*s1 != '\0')
	{
		if (*s1 == c)
		{
			if (start != s1)
				ft_mem_fill_or_free(k++, array, start, c);
			start = (char *)s1 + 1;
		}
		s1++;
	}
	if (start != s1)
		ft_mem_fill_or_free(k++, array, start, c);
	array[k] = 0;
	return (array);
}
