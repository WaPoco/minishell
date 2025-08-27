/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_quoted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 13:12:54 by hmote             #+#    #+#             */
/*   Updated: 2025/07/25 13:46:34 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_quoted(int index, const char *s)
{
	int	i;
	int	in_single;
	int	in_double;

	i = 0;
	in_single = 0;
	in_double = 0;
	while (i <= index && s[i])
	{
		if (s[i] == '\'' && !in_double)
			in_single = !in_single;
		else if (s[i] == '"' && !in_single)
			in_double = !in_double;
		i++;
	}
	return (in_single || in_double);
}
