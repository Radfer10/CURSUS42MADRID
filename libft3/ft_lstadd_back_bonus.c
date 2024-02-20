/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:56:31 by rde-migu          #+#    #+#             */
/*   Updated: 2024/02/19 20:20:14 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = *lst;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while (last->next)
		last = last->next;
	last->next = new;
}
/*int main()
{
	t_list	*lst = ft_lstnew("Hola");
	ft_lstadd_back(&lst, ft_lstnew("Que tal"));
	while(lst)
	{
		printf("%s\n", (char *) lst->content);
		lst = lst->next;
	}
	t_lstclear(lst, free);
	return (0);
}*/
