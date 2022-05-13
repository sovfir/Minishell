/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_vars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshonta <lshonta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 20:08:01 by lshonta           #+#    #+#             */
/*   Updated: 2022/05/13 18:04:37 by lshonta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"



static char *split_env_vars(char *s, bool dol_at_end, t_env_v *env_v)
{
	char *ret;
	char **split;
	int i;

	split = ft_split_env(s, '$'); // ****
	if (split == NULL)
		return (NULL);
	i = 1;
	if (s[0] == '$')
		i = 0;
	else
		ret = ft_strdup(split[0]);
	while (split[i] != NULL)
	{
		split[i] = replace_env_var(split, env_v, i); // *****
		if (i == 0)
			ret = ft_strdup(split[0]);
		else
			ret = ft_append(ret, split[i]);
		i++;
	}
	
}

char	*env_vars(char *s, t_env_v *env_v)
{
	bool	dol_at_end;
	char *ret;
	int len;

	if (ft_strchr(s, '$') < 0)
		return (s);
	dol_at_end = false;
	len = ft_strclen(s, '\0');
	if (len >= 2 && s[len -1] == '$' && s[len - 2] != '$')
		dol_at_end = true;
	ret = split_env_vars(s, dol_at_end, env_v); // ****
	if (ret == NULL)
		return (s);
	free(s);
	return (ret);
}