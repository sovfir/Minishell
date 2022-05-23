/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshonta <lshonta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:28:10 by lshonta           #+#    #+#             */
/*   Updated: 2022/05/23 17:28:10 by lshonta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	del_env(t_env_v **env, char *name)
{
	t_env_v	*tmp;
	t_env_v	*prev;

	tmp = *env;
	if (tmp != NULL && ft_strcmp(tmp->name, name) == 0)
	{
		*env = tmp->next;
		free(tmp->name);
		free(tmp->value);
		free(tmp);
		return ;
	}
	while (tmp != NULL && ft_strcmp(tmp->name, name) != 0)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp == NULL)
		return ;
	prev->next = tmp->next;
	free(tmp->name);
	free(tmp->value);
	free(tmp);
}

void	unset(t_env_v **env_v, char *arg)
{
	char	*name;

	name = arg;
	if (arg == NULL || ft_strcmp(name, "?") == 0)
	{
		rep_env(env_v, ft_strdup("?"), ft_strdup("0"), false);
		return ;
	}
	else if (ft_strchr(arg, '$') >= 0 || ft_strchr(arg, '/') >= 0)
	{
		ft_write_error("unset", arg, "not a valid identifier");
		rep_env(env_v, ft_strdup("?"), ft_strdup("1"), false);
		return ;
	}
	else if (search_env(*env_v, name) == true)
		del_env(env_v, name);
	rep_env(env_v, ft_strdup("?"), ft_strdup("0"), false);
}
