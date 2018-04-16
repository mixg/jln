/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxiong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:07:43 by mxiong            #+#    #+#             */
/*   Updated: 2018/03/13 12:52:56 by mxiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_link;

	new_link = (t_list *)malloc(sizeof(t_list));
	if (new_link == NULL)
		return (NULL);
	if (content == NULL)
	{
		new_link->content = NULL;
		new_link->content_size = 0;
	}
	else
	{
		new_link->content =
			(t_list *)malloc(sizeof(*content) * content_size + 1);
		if (new_link->content == NULL)
			return (NULL);
		ft_memcpy(new_link->content, content, content_size);
		new_link->content_size = content_size;
		new_link->next = NULL;
	}
	return (new_link);
}
