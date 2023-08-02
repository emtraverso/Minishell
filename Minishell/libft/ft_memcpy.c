/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardi <mgirardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 23:58:07 by mgirardi          #+#    #+#             */
/*   Updated: 2023/03/25 23:58:08 by mgirardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*ptd;
	char	*pts;
	size_t	i;

	ptd = (char *)dest;
	pts = (char *)src;
	i = 0;
	while (i < n)
	{
		ptd[i] = pts[i];
		i++;
	}
	return (dest);
}
