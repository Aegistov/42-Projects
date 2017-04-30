#include "ft_db.h"

// void	display_records(char **parsed_record)
// {
//   int   count;
//
//   count = -1;
//   while (parsed_record[++count])
//   {
//     printf("%s\t", parsed_record[count]);
//   }
// }

void	parse_record(char *record_entry, const size_t entry_number)
{
	char	*parsed;

	parsed = strtok(record_entry, ",");
	printf("%zu\t", entry_number);
	while (parsed)
	{
		printf("%s\t\t", parsed);
		parsed = strtok(NULL, ",");
	}
	printf("\n");
	// display_records(parsed);
}

int		read_file(FILE *table)
{
	char	*record_entry;
	size_t	getline_return;
	size_t	nbytes;
	size_t	entry_number;

	entry_number = 0;
	nbytes = 100;
	while (1)
	{
		getline_return = getline(&record_entry, &nbytes, table);
		if (getline_return != strlen(record_entry))
			break ;
		parse_record(record_entry, entry_number);
		entry_number++;
	}
	return (1);
}
