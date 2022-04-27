/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshonta <lshonta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:52:34 by lshonta           #+#    #+#             */
/*   Updated: 2022/04/27 20:02:37 by lshonta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// char	**convert_token(t_token *token)
// {
// 	char **ret;
// 	t_token	*tmp;
// 	int i;
	
// 	tmp = token;
// 	i = 0;
// 	while (tmp != NULL && tmp->type == NONE)
// 	{
// 		tmp = tmp->next;
// 		i++;
// 	}
// 	ret = ft_calloc(i + 1, sizeof(char *));
// 	if (ret == NULL)
// 		return (NULL);
// 	tmp = token;
// 	i = 0;
// 	while (tmp != NULL && tmp->type == NONE)
// 	{
// 		ret[i] = ft_strdup(tmp->value);
// 		tmp = tmp->next;
// 		i++;
// 	}
// 	ret[i] = NULL;
// 	return (ret);
// }  