/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardi <mgirardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 23:57:23 by mgirardi          #+#    #+#             */
/*   Updated: 2023/03/25 23:57:25 by mgirardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;

	if (lst != NULL)
	{
		temp = lst;
		while (temp)
		{
			(*f)(temp->content);
			temp = temp->next;
			if (temp == NULL)
				return ;
		}
	}
}
