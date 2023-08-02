/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardi <mgirardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 00:01:04 by mgirardi          #+#    #+#             */
/*   Updated: 2023/03/26 00:01:07 by mgirardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*i;

	i = 0;
	while (*s)
	{
		if (*s == (unsigned char)c)
			i = (char *)s;
		s++;
	}
	if (i)
		return (i);
	if (c == '\0')
		return ((char *)s);
	return (0);
}
