#include "ft_db.h"

// void  parse_header(char *header)
// {
//
// }

int   add_record(FILE *table)
{
  char    *header;
  size_t  nbytes;
  size_t  entry_number;
  size_t  getline_return;
  char    *parsed_header;
  char    cell_entry[100];
  char    record_entry[200];

  entry_number = 0;
  nbytes = 100;
  // while (1)
	// {
    printf("getting line\n");
		getline_return = getline(&header, &nbytes, table);
		// if (getline_return != strlen(header))
		// 	break ;
    //seg fault happens before this point in *getline*
    printf("test: %s\n", header);
		// entry_number++;
	// }
  parsed_header = strtok(header, ",");
  printf("got line: %s\n", header);
  while (parsed_header)
  {
    printf("Add %s: ", parsed_header);
    scanf("%s", cell_entry);
    strcat(record_entry, cell_entry);
    record_entry[strlen(record_entry)] = ',';
    record_entry[strlen(record_entry) + 1] = '\0';
	printf("%s\n", record_entry);
    parsed_header = strtok(NULL, ",\n");
  }
  // record_entry[strlen(record_entry) - 1] = '\n';
  // parse_header(header);
  // before or after entry
  // entry_count()
  return (1);
}
