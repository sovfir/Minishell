/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacinta <gjacinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:00:00 by gjacinta          #+#    #+#             */
/*   Updated: 2022/04/07 14:00:34 by gjacinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_append(char *start, char *end)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	tmp = malloc(ft_strclen(start, '\0') + ft_strclen(end, '\0') + 1);
	if (tmp == NULL)
		return (NULL);
	i = 0;
	while (start[i] != '\0')
	{
		tmp[i] = start[i];
		i++;
	}
	j = 0;
	while (end[j] != '\0')
	{
		tmp[i] = end[j];
		i++;
		j++;
	}
	tmp[i] = '\0';
	free(start);
	return (tmp);
}