#include "libftprintf.h"

int	ft_printf_capture_flags(const char *restrict format, char *flags, int index)
{
	int		count;

	count = 0;
	printf("%d\n", index);
	while (format[index] == '-' || format[index] == '0' || format[index] == '+' || format[index] == '#' || format[index] == ' ')
	{
		flags[count] = format[index];
		flags[count + 1] = '\0';
		// printf("Format: %c\nFlags: %s\n", format[index], flags);
		index += 1;
		count++;
	}
	return (count);
}
