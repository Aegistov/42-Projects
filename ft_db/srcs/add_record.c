#include "ft_db.h"

int   add_record(FILE *table, char *table_name)
{
  char    *header;
  size_t  nbytes;
  size_t  getline_return;
  char    *parsed_header;
  char    cell_entry[100];
  char    record_entry[200];

  nbytes = 100;
	getline_return = getline(&header, &nbytes, table);
  table = freopen(table_name, "a", table);
  parsed_header = strtok(header, ",");
  while (parsed_header)
  {
    printf("Add %s: ", parsed_header);
    scanf("%s", cell_entry);
    strcat(record_entry, cell_entry);
    record_entry[strlen(record_entry)] = ',';
    record_entry[strlen(record_entry) + 1] = '\0';
    parsed_header = strtok(NULL, ",\n");
  }
  record_entry[strlen(record_entry) - 1] = '\n';
  printf("%s", record_entry);
  fprintf(table, "%s", record_entry);
  return (1);
}
