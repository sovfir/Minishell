/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshonta <lshonta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:28:04 by lshonta           #+#    #+#             */
/*   Updated: 2022/05/23 17:28:05 by lshonta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	pwd(t_env_v *env_v)
{
	char	*cwd;

	cwd = ft_calloc(PATH_MAX, 1);
	if (cwd == NULL)
		return ;
	getcwd(cwd, PATH_MAX);
	if (cwd[0] == '\0')
	{
		ft_write_error(NULL, "pwd", "path too long");
		return ;
	}
	cwd = ft_append(cwd, "\n");
	write(1, cwd, ft_strclen(cwd, '\0'));
	free(cwd);
	rep_env(&env_v, ft_strdup("?"), ft_strdup("0"), false);
}
