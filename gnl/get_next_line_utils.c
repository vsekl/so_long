/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:11:54 by vjose             #+#    #+#             */
/*   Updated: 2021/10/19 13:11:54 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	counter;

	counter = 0;
	while (s[counter] != '\0')
		counter++;
	return (counter);
}

void	*ft_memcpy(void	*dest, const void	*src, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *) dest;
	ptr2 = (unsigned char *) src;
	if (ptr1 == NULL && ptr2 == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		ptr1[i] = ptr2[i];
		i++;
	}
	return (dest);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s) + 1;
	str = malloc(sizeof(char) * len);
	if (str == 0)
		return (NULL);
	str = ft_memcpy(str, s, len);
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (s != NULL)
	{
		if (start >= ft_strlen(s))
			return (ft_strdup("\0"));
		if (start + len > ft_strlen(s))
			len = ft_strlen(s) - start;
		str = malloc(sizeof(char) * (len + 1));
		if (str == NULL)
			return (NULL);
		str = ft_memcpy(str, s + start, len);
		str[len] = '\0';
		return (str);
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;
	size_t	len_s1;
	size_t	len_s2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	len = len_s1 + len_s2 + 1;
	str = malloc(sizeof(char) * len);
	if (str == 0)
		return (NULL);
	ft_memcpy(str, s1, len_s1);
	ft_memcpy(str + len_s1, s2, len_s2);
	str[len - 1] = '\0';
	return (str);
}
