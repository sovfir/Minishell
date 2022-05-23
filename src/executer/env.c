/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshonta <lshonta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:27:40 by lshonta           #+#    #+#             */
/*   Updated: 2022/05/23 17:27:41 by lshonta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	env(t_env_v *env_v, char *arg)
{
	t_env_v	*tmp;

	if (arg != NULL)
		return ;
	tmp = env_v;
	while (tmp != NULL)
	{
		if (tmp->export == true)
			printf("%s=%s\n", tmp->name, tmp->value);
		tmp = tmp->next;
	}
	rep_env(&env_v, ft_strdup("?"), ft_strdup("0"), false);
}
