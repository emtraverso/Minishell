/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardi <mgirardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 00:04:58 by mgirardi          #+#    #+#             */
/*   Updated: 2023/03/26 00:05:30 by mgirardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_of_gondo(t_env *sp)
{
	t_token	*temp;
	int		fd;
	char	*s1;
	char	*s2;

	temp = sp->tk;
	while (temp->type != 'm')
		temp = temp->next;
	fd = open(temp->str, O_RDONLY);
	s1 = ft_calloc(1, 1);
	s2 = get_next_line(fd);
	while (s2)
	{
		s1 = ft_strjoin(s1, s2);
		free(s2);
		s2 = get_next_line(fd);
	}
	free(s2);
	free(temp->str);
	temp->str = s1;
	temp->type = 'm';
	return ;
}

void	ft_adda_schifo(t_env *sp)
{
	t_token	*temp;
	t_token	*temp2;
	t_token	*schifo;

	temp = sp->tk;
	while (temp->type != 'm')
		temp = temp->next;
	temp->type = 's';
	temp2 = temp->prev;
	schifo = ft_calloc(sizeof(t_token), 1);
	schifo->str = ft_strdup("<");
	schifo->type = '<';
	temp2->next = schifo;
	schifo->next = temp;
	temp->prev = schifo;
	schifo->prev = temp2;
}

t_token	*ft_lstsearch(t_token *temp, char c)
{
	while (temp->prev != NULL)
	{
		if (temp->prev->type == c)
			return (temp);
		temp = temp->prev;
	}
	return (temp);
}

t_token	*ft_leftargs(t_token *tk, char c)
{
	t_token	*left;
	t_token	*tleft;
	t_token	*templeft;
	t_token	*temp;

	temp = tk;
	left = malloc(sizeof(t_token));
	left->prev = NULL;
	temp = ft_lstsearch(temp, c);
	templeft = left;
	left->str = ft_strdup(temp->str);
	left->type = temp->type;
	temp = temp->next;
	while (temp->type != c)
	{
		tleft = malloc(sizeof(t_token));
		tleft->str = ft_strdup(temp->str);
		tleft->type = temp->type;
		templeft->next = tleft;
		temp = temp->next;
		templeft = templeft->next;
	}
	templeft->next = NULL;
	return (left);
}
