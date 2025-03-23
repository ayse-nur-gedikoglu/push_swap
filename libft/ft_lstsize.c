/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agedikog <gedikoglu_27@icloud.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 22:25:06 by agedikog          #+#    #+#             */
/*   Updated: 2025/03/22 19:17:31 by agedikog         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 1;
	if (!lst)
		return (0);
	while (!(lst->next == NULL))
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
/* int main()
{
	t_list * ayse = ft_lstnew("ayse");
	t_list * ruzgar = ft_lstnew("Ruzgar");
	t_list * pelin =  ft_lstnew("pelin");
	t_list * mustafa =  ft_lstnew("mustafa");

	ft_lstadd_front(&ayse, ruzgar);
	ft_lstadd_front(&ruzgar, pelin);
	ft_lstadd_front(&pelin, mustafa);

	t_list *sondaki = ft_lstlast(mustafa);

	int lstsize = ft_lstsize(mustafa);

	printf("lstsize : %d\n", lstsize);
	printf("listin sonundaki content : %s\n", sondaki->content);
	printf("bu da listin sonundaki content : %s\n",mustafa->next->next->next->content);
} */