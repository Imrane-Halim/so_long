/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihalim <ihalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:32:44 by ihalim            #+#    #+#             */
/*   Updated: 2024/10/22 10:32:46 by ihalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*t_dst;
	const char	*t_src;

	if (dst == NULL && src == NULL)
		return (dst);
	if (n != 0)
	{
		t_dst = dst;
		t_src = src;
		while (n--)
			*t_dst++ = *t_src++;
	}
	return (dst);
}
