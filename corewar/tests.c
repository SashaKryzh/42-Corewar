
#include "libft.h"
#include "corewar.h"

void	putfile_hex(int ret, t_cell *file, int space, int newline)
{
	int j;

	j = 0;
	ft_printf("0x0000 : ");
	while (j < ret)
	{
		if (j != 0 && j % newline == 0)
			ft_printf("\n%#06x : ", j);
		ft_printf("%02x", file[j].v);
		if (space == 1)
			ft_printf(" ");
		else if (j % space == 1)
			ft_printf(" ");
		j++;
	}
	ft_printf("\n");
}

void	putbytes_bit(char *n, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_print_bits(n[i]);
		i != size - 1 ? ft_printf(" ") : ft_printf("");
		i++;
	}
	ft_printf("\n");
}

void	print_players(t_player *champs)
{
	int i;

	i = 0;
	while (champs[i].id != -1)
	{
		ft_printf("%d\n", champs[i].id);
		ft_printf("%s\n", champs[i].name);
		ft_printf("%s\n", champs[i].comment);
		ft_printf("%d\n", champs[i].code_size);
		i++;
		if (champs[i].id != -1)
			ft_printf("\n");
	}
}

void	print_cars(t_car *carriage)
{
	while (carriage)
	{
		ft_printf("id: %d, pos: %d, champ: %d, next: %p\n",
			carriage->id, carriage->position,
			carriage->regs[0], carriage->next);
		carriage = carriage->next;
	}
}

void	print_args_type(t_car *car)
{
	int i;

	i = 0;
	while (i < OP.args_num)
	{
		if (car->args_types[i] == (uint8_t)IND_CODE)
			ft_printf("IND ");
		else if (car->args_types[i] == (uint8_t)DIR_CODE)
			ft_printf("DIR ");
		else
			ft_printf("REG ");
		i++;
	}
	ft_printf("\n");
}
