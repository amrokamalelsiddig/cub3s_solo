/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:15:05 by aelsiddi          #+#    #+#             */
/*   Updated: 2023/05/31 19:19:31 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


static int	ft_nbrlen(int nbr)
{
	int	len;
	int	mod;

	len = 1;
	if (nbr > 0)
		mod = nbr / 10;
	else
	{
		mod = -nbr / 10;
		len++;
	}	
	while (mod > 0)
	{
		len++;
		mod = mod / 10;
	}
	return (len);
}

char	*ft_strdup(const char	*s1)
{
	char	*s;
	char	*ptr;
	int		i;

	i = 0;
	s = (char *)s1;
	ptr = (char *)malloc(ft_strlen(s) + 1);
	if (!ptr)
		return (0);
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*ft_reverse(char *src)
{
	char	temp;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen((const char *)src);
	while (i < len / 2)
	{
		temp = src[i];
		src[i] = src[len - 1 - i];
		src[len - 1 - i] = temp;
		i++;
	}
	return (src);
}

static char	*ft_handle(int z)
{
	if (z == 0)
		return (ft_strdup("0"));
	return (ft_strdup("-2147483648"));
}

char	*ft_itoa(int n)
{
	char	*result;
	int		temp;
	int		mod;
	int		i;

	i = 0;
	temp = n;
	if (n == 0 || n == -2147483648)
		return (ft_handle(n));
	if (temp < 0)
		temp = -temp;
	result = (char *)malloc(ft_nbrlen(n) + 1);
	if (!result)
		return (0);
	while (temp > 0)
	{
		mod = temp % 10;
		result[i] = mod + '0';
		temp = temp / 10;
		i++;
	}
	if (n < 0)
		result[i++] = '-';
	result[i] = '\0';
	return (ft_reverse(result));
}


char	*ft_strjoin(char const *s1, char const	*s2)
{
	char	*f;
	char	*se;
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	se = (char *)s2;
	f = (char *)s1;
	if (!s1 || !s2)
		return (NULL);
	ptr = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!ptr)
		return (ptr);
	while (f && f[i] != '\0')
		ptr[i++] = f[j++];
	j = 0;
	while (se && se[j] != '\0')
		ptr[i++] = se[j++];
	ptr[i] = '\0';
	return (ptr);
}

void	*ft_calloc(size_t	count, size_t size)
{
	void	*result;

	result = malloc(count * size);
	if (!result)
		return (0);
	ft_bzero(result, count * size);
	return (result);
}

void	ft_bzero(void	*s,	size_t	n)
{
	unsigned int	i;
	unsigned char	*temp;

	i = 0;
	temp = (unsigned char *)s;
	while (i < n)
	{
		*(temp + i) = 0;
		i++;
	}
}
