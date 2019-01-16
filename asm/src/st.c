/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 15:07:04 by amoroziu          #+#    #+#             */
/*   Updated: 2019/01/16 16:38:53 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static int	valid(t_token **cur)
{
	if (!(*cur)->next || (*cur)->next->type != REGISTER)
		return (err_mesg(NEXT_TOKEN_MUST_BE_REGISTER, (*cur)->line));
	if (!(*cur)->next->next || (*cur)->next->next->type != SEPARATOR)
		return (err_mesg(SEPARATOR_IS_MISSING, (*cur)->line));
	if (!(*cur)->next->next->next || !((*cur)->next->next->next->type
		== REGISTER || (*cur)->next->next->next->type == INDIRECT_VALUE ||
		(*cur)->next->next->next->type == INDIRECT_LABEL))
		return (err_mesg(NEXT_TOKEN_MUST_BE_DIR_OR_IN, (*cur)->line));
	if ((*cur)->next->next->next->next &&
		(*cur)->next->next->next->next->line == (*cur)->line)
		return (err_mesg(ONLY_ONE_INSTRUCTION, (*cur)->line));
	return (1);
}

static void	add_codes(t_asm *champ, t_token **cur)
{
	int32_t	arg_code;

	arg_code = 64;
	if ((*cur)->next->next->type == DIRECT_LABEL ||
		(*cur)->next->next->type == DIRECT_VALUE)
		arg_code += 32;
	else
		arg_code += 48;
	add_to_code(champ, int_to_hex(arg_code, 1));
}

static void	add_second(t_asm *champ, t_token **cur)
{
	if ((*cur)->type == INDIRECT_VALUE)
	{
		add_to_code(champ, int_to_hex(ft_atoi((*cur)->value), 2));
		return ;
	}
	if ((*cur)->type == REGISTER)
	{
		add_to_code(champ, int_to_hex(ft_atoi((*cur)->value), 1));
		return ;
	}
	if (!get_label_value((*cur)->value, champ, 2))
	{
		add_new_missed(champ, 2, (*cur)->value);
		add_to_code(champ, ft_strdup("0000"));
	}
}

int			st(t_asm *champ, t_token **cur)
{
	if (!valid(cur))
		return (0);
	add_to_code(champ, ft_strdup("03"));
	add_codes(champ, cur);
	*cur = (*cur)->next;
	add_to_code(champ, int_to_hex(ft_atoi((*cur)->value), 1));
	*cur = (*cur)->next;
	*cur = (*cur)->next;
	add_second(champ, cur);
	*cur = (*cur)->next;
	return (1);
}
