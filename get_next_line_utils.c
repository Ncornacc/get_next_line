/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                     :+:    :+:           */
/*                                                     +:+                    */
/*   By: ncornacc <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 15:46:12 by ncornacc      #+#    #+#                 */
/*   Updated: 2022/11/01 16:12:33 by ncornacc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	char	*ptr;
    int     i;
    int     k;

	if (!s1 && !s2)
		return (NULL);
    i = -1;
    k = 0;
	total_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	ptr = malloc(sizeof(char) * (total_len));
	if (!ptr)
		return (0);
    while(s1[++i])
	{
		ptr[i] = s1[i];
	}
    while(s2[k])
	{
        ptr[i++] = s2[k++];
	}
	ptr[total_len - 1] = '\0';
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (0);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	int		i;
	int		bytes_s;

	i = 0;
	bytes_s = nmemb * size;
	ptr = malloc(bytes_s);
	if (ptr == NULL)
		return (0);
	while (bytes_s > 0)
	{
		ptr[i] = '\0';
		i++;
		bytes_s--;
	}
	return ((void *)ptr);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
