/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardi <mgirardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 23:58:43 by mgirardi          #+#    #+#             */
/*   Updated: 2023/03/25 23:58:44 by mgirardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_s(char *stringa, int fd, int *count)
{
	if (!stringa)
		ft_putstrs_fd("(null)", fd, count);
	else
		ft_putstrs_fd(stringa, fd, count);
}
