/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshonta <lshonta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:25:43 by lshonta           #+#    #+#             */
/*   Updated: 2022/05/23 17:25:44 by lshonta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_strdup(const char *s1)
{
	char	*p;
	size_t	i;
	size_t	l;

	l = ft_strclen(s1, '\0') + 1;
	i = 0;
	p = malloc(sizeof(char) * l);
	if (p == NULL)
		return (NULL);
	while (i < l)
	{
		p[i] = s1[i];
		i++;
	}
	return (p);
}
