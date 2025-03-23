/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agedikog <gedikoglu_27@icloud.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:32:39 by agedikog          #+#    #+#             */
/*   Updated: 2024/10/30 12:57:06 by agedikog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	int		str_len;

	str_len = ft_strlen(s)+1;
	str = malloc(str_len);
	if (str)
	{
		ft_strlcpy(str, s, str_len);
		return (str);
	}
	return (NULL);
}
