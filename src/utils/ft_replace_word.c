/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_word.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshonta <lshonta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:24:43 by lshonta           #+#    #+#             */
/*   Updated: 2022/05/23 17:24:44 by lshonta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_replace_word(char *s, char *replace)
{
	char	*ret;
	int		pos;

	if (replace == NULL)
		replace = "\0";
	ret = ft_strcdup(replace, '\0', 0);
	pos = 0;
	while (s[pos] != ' ' && s[pos] != '\0' && s[pos] != '\'' && s[pos] != '"')
		pos++;
	ret = ft_append(ret, &s[pos]);
	return (ret);
}
