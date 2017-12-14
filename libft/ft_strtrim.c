/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 14:41:40 by vibondar          #+#    #+#             */
/*   Updated: 2017/11/06 14:41:42 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t			i;
	size_t			j;
	size_t			len;
	unsigned char	*s_cp;

	i = 0;
	j = 1;
	if (!s)
		return (0);
	len = ft_strlen(s);
	if ((s_cp = (unsigned char *)malloc(sizeof(unsigned char) * len + 1)) == 0)
		return (0);
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t' || s[i] == '\0') && s)
		i++;
	while ((s[len - j] == ' ' || s[len - j] == '\n' || s[len - j] == '\t') && s)
		j++;
	if (i == j || ft_strlen(s) == 0)
		return (ft_strdup(""));
	return (ft_strsub(s, i, (size_t)(len - i - j + 1)));
}
