/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardi <mgirardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 00:00:59 by mgirardi          #+#    #+#             */
/*   Updated: 2023/03/26 00:01:00 by mgirardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	int		j;

	i = -1;
	if (*little == '\0')
		return ((char *)big);
	while (big[++i] != '\0' && i <= len)
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (big[i] == little[j] && little[j] != '\0' && i <= len)
			{
				i++;
				j++;
			}
		}
		if (little[j] == '\0' && i <= len)
		{
			i -= j;
			return ((char *)&big[i]);
		}
		i -= j;
	}
	return (NULL);
}
