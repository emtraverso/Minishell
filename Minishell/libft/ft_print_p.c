/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardi <mgirardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 23:58:36 by mgirardi          #+#    #+#             */
/*   Updated: 2023/03/25 23:58:38 by mgirardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_p(uintptr_t nbr, int fd, int *count)
{
	if (!nbr)
		ft_putstrs_fd("(nil)", fd, count);
	else
	{
		ft_putstrs_fd("0x", fd, count);
		ft_putnbr_base_fd(nbr, fd, count);
	}
}
