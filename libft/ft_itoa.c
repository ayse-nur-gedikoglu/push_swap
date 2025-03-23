/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agedikog <gedikoglu_27@icloud.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 21:11:39 by agedikog          #+#    #+#             */
/*   Updated: 2024/10/30 13:06:52 by agedikog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	numb_len(int c)
{
	int	i;

	i = 0;
	if (c == 0)
		return (1);
	if (c < 0)
		i++;
	while (c != 0)
	{
		c = c / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	number;
	int		numb_l;
	char	*str;

	number = 0;
	numb_l = numb_len(n);
	str = (char *) malloc(sizeof(char) * (numb_l + 1));
	if (str == NULL)
		return (NULL);
	if ((long)n < 0)
	{
		str[0] = '-';
		number = -(long)n;
	}
	else
		number = (long)n;
	if (number == 0)
		str[0] = '0';
	str[numb_l++] = '\0';
	while (number != 0 && numb_l--)
	{
		str[numb_l - 1] = (number % 10) + '0';
		number /= 10;
	}
	return (str);
}
