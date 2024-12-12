/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihalim <ihalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:32:14 by ihalim            #+#    #+#             */
/*   Updated: 2024/10/26 12:03:00 by ihalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_size(int n)
{
	int	i;

	i = 2;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 9)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	i;
	int		size;
	char	*str;

	i = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = count_size(n);
	str = malloc(sizeof(char) * (size));
	if (str == NULL)
		return (NULL);
	if (n < 0)
		n = -n;
	str[--size] = '\0';
	while (--size >= 0)
	{
		str[size] = (n % 10) + '0';
		n /= 10;
	}
	if (i < 0)
		*str = '-';
	return (str);
}
