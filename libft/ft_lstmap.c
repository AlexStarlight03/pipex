/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandrinedube <alexandrinedube@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:25:22 by adube             #+#    #+#             */
/*   Updated: 2023/07/24 14:59:08 by alexandrine      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_pile	*ft_lstmap(t_pile *lst, void *(*f)(void *), void (*del)(void *))
{
	t_pile	*newlist;
	t_pile	*temp;
	void	*content;

	newlist = 0;
	temp = 0;
	if (lst == NULL)
		return (NULL);
	while (lst)
	{
		content = f(lst->content);
		temp = ft_lstnew(content);
		if (temp == NULL)
		{
			ft_lstclear(&newlist, del);
			free(content);
			return (NULL);
		}
		ft_lstadd_back(&newlist, temp);
		lst = lst->next;
	}
	return (newlist);
}
