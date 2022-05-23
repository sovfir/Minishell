/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshonta <lshonta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:28:20 by lshonta           #+#    #+#             */
/*   Updated: 2022/05/23 17:28:21 by lshonta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	add_env(t_env_v **env_v, char *name, char *value, bool export)
{
	t_env_v	*new;

	new = new_node();
	new->name = name;
	new->value = value;
	new->export = export;
	ft_lstadd_back(env_v, new);
}

void	rep_env(t_env_v **env_v, char *name, char *value, bool export)
{
	t_env_v	*tmp;

	tmp = *env_v;
	if (tmp != NULL && ft_strcmp(tmp->name, name) == 0)
	{
		free(tmp->value);
		tmp->value = value;
		tmp->export = export;
		return ;
	}
	while (tmp != NULL && ft_strcmp(tmp->name, name) != 0)
		tmp = tmp->next;
	if (tmp == NULL)
		return ;
	free(tmp->value);
	free(name);
	tmp->value = value;
	tmp->export = export;
}
