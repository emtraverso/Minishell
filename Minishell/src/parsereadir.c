/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsereadir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardi <mgirardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 00:05:01 by mgirardi          #+#    #+#             */
/*   Updated: 2023/03/26 00:05:29 by mgirardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_primogenito(t_env *sp, t_token *args, int *p)
{
	char	*buf;
	char	*filename;
	int		fd;

	buf = calloc(1, 1);
	filename = ft_strdup(args->str);
	fd = open(filename, O_RDONLY, S_IRUSR | S_IWUSR);
	free(filename);
	if (fd < 0)
	{
		free(buf);
		ft_release(sp);
		exit(1);
	}
	while (buf)
	{
		free(buf);
		buf = get_next_line(fd);
		if (buf)
			ft_putstr_fd(buf, p[1]);
	}
	close(fd);
}

void	ft_nipotino(t_env *sp, int *p)
{
	sp->son = 1;
	dup2(p[0], 0);
	close(p[1]);
	ft_passerone(sp, sp->pwd);
	close(p[0]);
	ft_special_release(sp);
	exit(0);
}

void	ft_faimosse(t_env *sp, t_path *pwd)
{
	ft_individua_partenopei(sp);
	ft_pulizia_vesuvio(sp);
	if (ft_cerca_il_milanese(sp))
		ft_passerone(sp, pwd);
}

void	ft_parsereadir(t_env *sp, t_token *args, t_path *pwd)
{
	int		p[2];

	sp->pid = fork();
	if (sp->pid == 0)
	{
		sp->son = 1;
		if (pipe(p) < 0)
			exit(1);
		args->type = 'z';
		args = args->next;
		args->type = 'z';
		ft_primogenito(sp, args, p);
		ft_individua_partenopei(sp);
		ft_pulizia_vesuvio(sp);
		sp->pid = fork();
		if (sp->pid == 0)
			ft_nipotino(sp, p);
		close(p[1]);
		close(p[0]);
		wait(0);
		ft_special_release(sp);
		exit(0);
	}
	wait(0);
	ft_faimosse(sp, pwd);
}
