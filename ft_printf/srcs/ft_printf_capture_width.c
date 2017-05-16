#include "../libftprintf.h"

int		ft_printf_capture_width(const char *restrict format, int *width, int index)
{
	int		count;
	char	*number;
	char	*tmp;

	if(!(number = (char *)malloc(2)))
		return (-1);
	count = 0;
	if (format[index] >= 48 && format[index] <= 57)
	{
		number[count++] = format[index++];
		number[count] = '\0';
		while (format[index] >= 48 && format[index] <= 57)
		{
			if(!(tmp = (char *)malloc(ft_strlen(number) + 2)))
				return (-1);
			ft_strcpy(tmp, number);
			tmp[count++] = format[index++];
			tmp[count] = '\0';
			free(number);
			number = tmp;
			// printf("Number is: %s\n", number);
		}
		*width = ft_atoi(number);
		return (count);
	}
	return (0);
}