/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:52:49 by adube             #+#    #+#             */
/*   Updated: 2023/09/04 15:31:41 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/pipex.h"

void	closing(t_pipex *pipex)
{
	close(pipex->tube[0]);
	close(pipex->tube[1]);
}

void	mess_err(char *err)
{
	perror(err);
	exit (1);
}

int	p_err(char *err_mess)
{
	if (err_mess == NULL)
		ft_putendl_fd("[ERROR]", STDERR_FILENO);
	else
		ft_putendl_fd(err_mess, STDERR_FILENO);
	return (1);
}

void	parent_free(t_pipex *pipex)
{
	int	i;

	i = 0;
	close(pipex->infile);
	close(pipex->outfile);
	while (pipex->cmd_paths[i])
	{
		free(pipex->cmd_paths[i]);
		i++;
	}
	free(pipex->cmd_paths);
}

void	child_free(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->cmd_arg[i])
	{
		free(pipex->cmd_arg[i]);
		i++;
	}
	free(pipex->cmd_arg);
	free(pipex->cmd);
}
