/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agedikog <gedikoglu_27@icloud.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:16:35 by agedikog          #+#    #+#             */
/*   Updated: 2024/10/26 21:06:50 by agedikog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmp;
	unsigned char	tmpc;
	size_t			i;

	tmp = b;
	i = 0;
	tmpc = c;
	if (len == 0)
		return (b);
	while (i < len)
	{
		tmp[i] = tmpc;
		i++;
	}
	return (b);
}
