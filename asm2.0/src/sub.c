/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 15:07:16 by amoroziu          #+#    #+#             */
/*   Updated: 2019/01/15 15:06:00 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static int	valid(t_token **cur)
{
	if (!(*cur)->next || (*cur)->next->type != REGISTER)
		return (err_mesg(NEXT_TOKEN_MUST_BE_REGISTER, (*cur)->line));
	if (!(*cur)->next->next || (*cur)->next->next->type != SEPARATOR)
		return (err_mesg(SEPARATOR_IS_MISSING, (*cur)->line));
	if (!(*cur)->next->next->next ||
		(*cur)->next->next->next->type != REGISTER)
		return (err_mesg(NEXT_TOKEN_MUST_BE_REGISTER, (*cur)->line));
	if (!(*cur)->next->next->next->next
		|| (*cur)->next->next->next->next->type != SEPARATOR)
		return (err_mesg(SEPARATOR_IS_MISSING, (*cur)->line));
	if (!(*cur)->next->next->next->next->next
		|| (*cur)->next->next->next->next->next->type != REGISTER)
		return (err_mesg(NEXT_TOKEN_MUST_BE_REGISTER, (*cur)->line));
	if ((*cur)->next->next->next->next->next->next &&
		(*cur)->next->next->next->next->next->next->line == (*cur)->line)
		return (err_mesg(ONLY_ONE_INSTRUCTION, (*cur)->line));
	return (1);
}

int			sub(t_asm *champ, t_token **cur)
{
	if (!valid(cur))
		return (0);
	add_to_code(champ, ft_strdup("\x05\xa4"));
	*cur = (*cur)->next;
	add_to_code(champ, int_to_hex(ft_atoi((*cur)->value), 1));
	*cur = (*cur)->next;
	*cur = (*cur)->next;
	add_to_code(champ, int_to_hex(ft_atoi((*cur)->value), 1));
	*cur = (*cur)->next;
	*cur = (*cur)->next;
	add_to_code(champ, int_to_hex(ft_atoi((*cur)->value), 1));
	*cur = (*cur)->next;
	return (1);
}
