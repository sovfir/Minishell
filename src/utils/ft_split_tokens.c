/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshonta <lshonta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:24:58 by lshonta           #+#    #+#             */
/*   Updated: 2022/05/23 17:24:59 by lshonta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*inner_string(int end, t_token *tokens)
{
	char	*ret;
	int		i;
	t_token	*tmp;

	i = 1;
	tmp = tokens->next;
	ret = ft_strdup(tokens->value);
	while (i < end)
	{
		ret = ft_append(ret, tmp->value);
		tmp = tmp->next;
		i++;
	}
	return (ret);
}

static int	ft_count_string(t_token *tokens, int type)
{
	t_token	*tmp;
	int		i;

	tmp = tokens;
	i = 1;
	while (tmp != NULL)
	{
		if (type == (int)tmp->type)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

char	**ft_split_tokens(t_token *tokens, int type)
{
	t_token	*tmp;
	char	**split;
	int		size;
	int		i;

	size = ft_count_string(tokens, type);
	split = malloc(size + 1 * sizeof(char *));
	split[size] = NULL;
	i = 0;
	size = 0;
	tmp = tokens;
	while (tmp != NULL)
	{
		if (type != (int)tmp->type)
		{
			split[i] = inner_string(size, tokens);
			i++;
		}
		size++;
		tmp = tmp->next;
	}
	return (split);
}
