/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacinta <gjacinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 13:27:46 by gjacinta          #+#    #+#             */
/*   Updated: 2022/04/07 13:43:58 by gjacinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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