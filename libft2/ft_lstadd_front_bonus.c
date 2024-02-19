/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:44:19 by rde-migu          #+#    #+#             */
/*   Updated: 2024/02/19 20:26:33 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_front(t_list **list, t_list *new)
{
	if (list && new)
	{
		new->next = *list;
		*list = new;
	}
}
/*int main()
{
	t_list	*lst = ft_lstnew("Hola");
	ft_lstadd_front(&lst, ft_lstnew("Que tal"));
	while(lst)
	{
		printf("%s\n", (char *) lst->content);
		lst = lst->next;
	}
	ft_lstclear(&lst, free);
	return (0);
}*/
