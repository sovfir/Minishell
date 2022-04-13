/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshonta <lshonta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:16:08 by gjacinta          #+#    #+#             */
/*   Updated: 2022/04/13 15:02:44 by lshonta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// char	*ft_strcdup(char *s, char c, int start)
// {
// 	char	*ret;
// 	int		i;

// 	ret = ft_calloc(ft_strclen(s, c) - start + 1, 1);
// 	if (ret == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (s[start] != c)
// 	{
// 		ret[i] = s[start];
// 		start ++;
// 		i++;
// 	}
// 	ret[i] = s[start];
// 	ret[i + 1] = '\0';
// 	return (ret);
// }
