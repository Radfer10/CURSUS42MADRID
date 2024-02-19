/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:27:36 by rde-migu          #+#    #+#             */
/*   Updated: 2024/02/19 20:34:48 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = (NULL);
	return (new_node);
}
/*int main()
{
	t_list	*lst= ft_lstnew("Holla");
	while (lst)
	{
		printf("%s\n", (char *) lst->content);
		lst->next;
	}
	ft_lstclear(&lst, free);
	return (0);
}*/
