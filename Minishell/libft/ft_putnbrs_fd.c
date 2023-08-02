/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrs_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardi <mgirardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 23:59:34 by mgirardi          #+#    #+#             */
/*   Updated: 2023/03/25 23:59:35 by mgirardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbrs_fd(int nb, int fd, int *count)
{
	unsigned int	n;

	if (nb < 0)
	{
		ft_putchars_fd('-', fd, count);
		n = (unsigned int)(nb * -1);
	}
	else
		n = (unsigned int)nb;
	if (n >= 10)
		ft_putnbrs_fd(n / 10, fd, count);
	ft_putchars_fd((char)(n % 10 + 48), fd, count);
}
