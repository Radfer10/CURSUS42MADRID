/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:32:17 by rde-migu          #+#    #+#             */
/*   Updated: 2024/02/19 20:27:27 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del) (void *))
{
	t_list	*current;
	t_list	*next;

	if (lst && del)
	{
		current = *lst;
		while (current)
		{
			next = current->next;
			del(current->content);
			free(current);
			current = next;
		}
		*lst = (NULL);
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
