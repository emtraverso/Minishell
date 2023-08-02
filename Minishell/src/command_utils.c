/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardi <mgirardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 00:04:12 by mgirardi          #+#    #+#             */
/*   Updated: 2023/03/26 00:06:35 by mgirardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_unset_init(t_env *sp)
{
	if (!sp->tk->next)
	{
		sp->exit = 0;
		return (1);
	}
	return (0);
}

int	ft_unset_logic(t_env *sp)
{
	int		j;
	int		i;
	t_token	*head;

	i = 0;
	head = sp->tk;
	sp->tk = sp->tk->next;
	while (sp->tk)
	{
		j = 0;
		while (sp->tk->str[j] != '=' && sp->tk->str[j])
			j++;
		ft_del_env(sp->tk->str, sp, j);
		while (sp->env[i])
			i++;
		if (sp->tk->next)
			sp->tk = sp->tk->next;
		else
		{
			sp->tk = head;
			return (1);
		}
	}
	return (0);
}

int	ft_unset(t_env *sp)
{
	if (ft_unset_init(sp))
		return (1);
	if (ft_unset_logic(sp))
		return (1);
	return (0);
}
