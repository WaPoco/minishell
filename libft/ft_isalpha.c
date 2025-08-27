/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmote <hmote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:33:08 by hmote             #+#    #+#             */
/*   Updated: 2025/04/08 22:28:00 by hmote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_islower(int c)
{
	return (c >= 97 && c <= 122);
}

static int	ft_isupper(int c)
{
	return (c >= 65 && c <= 90);
}

int	ft_isalpha(int c)
{
	return (ft_isupper(c) || ft_islower(c));
}
