/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agedikog <gedikoglu_27@icloud.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:52:26 by agedikog          #+#    #+#             */
/*   Updated: 2024/10/26 20:59:56 by agedikog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*s;

	s = (char *)str + ft_strlen(str);
	if (str == NULL)
		return (NULL);
	if ((char)c == '\0')
		return (s);
	while (s > str)
	{
		s--;
		if (*s == (char)c)
			return (s);
	}
	return (NULL);
}
