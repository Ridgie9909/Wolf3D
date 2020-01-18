/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 13:01:12 by rdube             #+#    #+#             */
/*   Updated: 2018/06/04 14:56:07 by rdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*ret_last;

	ret_last = f(lst);
	ret = ret_last;
	if (ret == NULL)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		ret_last->next = f(lst);
		if (ret_last->next == NULL)
			return (NULL);
		ret_last = ret_last->next;
	}
	return (ret);
}
