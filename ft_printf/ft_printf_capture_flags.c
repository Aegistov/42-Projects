#include "libftprintf.h"

int	ft_printf_capture_flags(const char *restrict format, t_mods *mod, int index)
{
	int		count;

	count = 0;
	// printf("cap_flags index: %d\n", index);
	while (format[index] == '-' || format[index] == '0' || format[index] == '+' || format[index] == '#' || format[index] == ' ')
	{
		if (format[index] == '-')
			mod->left_align = 1;
		if (format[index] == '0')
			mod->zero = 1;
		if (format[index] == '+')
			mod->plus = 1;
		if (format[index] == '#')
			mod->hash = 1;
		if (format[index] == ' ')
			mod->space = 1;
		// printf("Format: %c\nFlags: %s\n", format[index], flags);
		index += 1;
		count++;
	}
	// printf("[cap_flags] count: %d\n", count);
	return (count);
}
