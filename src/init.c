/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacinta <gjacinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:41:52 by gjacinta          #+#    #+#             */
/*   Updated: 2022/04/07 13:43:38 by gjacinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	add_env(t_env_v **env_v, char *name, char *value, bool export)
{
	t_env_v *new;

	new = ft_node();
	new->name = name;
	new->value = value;
	new->export = export;
	ft_lstadd_back(env_v, new);
}

void	free_spit(char **str)
{
	int	i;

	if (str == NULL)
		return ;
	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}


void	*ft_node()
{
	t_env_v	*new;

	new= malloc(sizeof(t_env_v));
	new->name = NULL;
	new->value = NULL;
	new->next = NULL;
	return (new);
}
void	init_env(t_env_v **env_v, char **envp)
{
	t_env_v *tmp;
	int		i;
	char	**split_str;

	i = 0;
	*env_v = ft_node();
	tmp = *env_v;
	while (envp[i] != NULL)
	{
		split_str = ft_split(envp[i], '=');
		(*env_v)->name = ft_strdup(split_str[0]);
		(*env_v)->value = ft_strdup(split_str[1]);
		(*env_v)->export = true;
		free_spit(split_str);
		if (envp[i + 1] == NULL)
			break ;
		(*env_v)->next = ft_node();
		(*env_v) = (*env_v)->next;
		i++;
	}
	*env_v = tmp;
}