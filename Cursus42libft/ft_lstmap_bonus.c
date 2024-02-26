/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:07:38 by rde-migu          #+#    #+#             */
/*   Updated: 2024/02/19 20:39:41 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*node;
	void	*mapped_content;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		mapped_content = f(lst->content);
		node = ft_lstnew(mapped_content);
		if (!node)
		{
			del(mapped_content);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, node);
		lst = lst->next;
	}
	return (new_lst);
}
/*int main()
{
	t_list	*lst = ft_lstnew("Hola");
	ft_lstadd_front(&lst, ft_lstnew("Que tal"));
	void *map_function(void *cotent);
	t_list	*mapped_lst = ft_lstmap (lst, map_fuction, (del));
	while(mapped_lst)
	{
		printf("%s\n", (char *) mapped_lstt->content);
		mapped_lst = mapped_lst->next;
	}
	ft_lstclear(&lst, free);
	ft_lstclear(&mapped_lst, free);
	return (0);
}*/
