/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:00:17 by rde-migu          #+#    #+#             */
/*   Updated: 2024/02/19 22:26:15 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
	{
		return (NULL);
	}
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}
/*int main()
{
	t_list	*lst = ft_lstnew("Hola");
	ft_lstadd_front(&lst, ft_lstnew("Que tal"));
	t_list	*last_node = ft_lstlast(lst);
	t_list	*original_lst = lst;
	while(lst)
	{
		printf("%s\n", (char *) lst->content);
		lst = lst->next;
	}
	if (last_node)
	{
		printf("%s\n", (char *) last_node->content);
	}
	ft_lstclear(&lst, free);
	return (0);
}*/
