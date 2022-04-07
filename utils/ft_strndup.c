/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacinta <gjacinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:21:58 by gjacinta          #+#    #+#             */
/*   Updated: 2022/04/07 14:22:14 by gjacinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strndup(const char *s1, int n)
{
	char	*s;
	int		i;

	i = 0;
	s = malloc(sizeof(char) + 1 * n);
	if (s == NULL)
		return (NULL);
	while (i < n && s1[i] != '\0')
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
