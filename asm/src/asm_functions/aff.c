/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 15:08:42 by amoroziu          #+#    #+#             */
/*   Updated: 2019/01/13 15:26:54 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

static int	valid(t_asm *champ, t_token **cur)
{
	if (!(*cur)->next || (*cur)->next->type != REGISTER)
		return (err_mesg(NEXT_TOKEN_MUST_BE_REGISTER, (*cur)->line));
	if ((*cur)->next->next && (*cur)->next->next->line == (*cur)->line)
		return (err_mesg(ONLY_ONE_INSTRUCTION, (*cur)->line));
	return (1);
}

int			aff(t_asm *champ, t_token **cur)
{
	char	*temp;

	if (!valid(champ, cur))
		return (0);
	add_to_code(champ, ft_strdup("1040"));
	*cur = (*cur)->next;
	add_to_code(champ, int_to_hex(ft_atoi((*cur)->value), 1));
	*cur = (*cur)->next;
	return (1);
}
