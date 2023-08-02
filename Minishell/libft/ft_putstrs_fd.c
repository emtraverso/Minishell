/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrs_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardi <mgirardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 23:59:51 by mgirardi          #+#    #+#             */
/*   Updated: 2023/03/25 23:59:51 by mgirardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrs_fd(char *s, int fd, int *count)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchars_fd(s[i], fd, count);
		i++;
	}
}
