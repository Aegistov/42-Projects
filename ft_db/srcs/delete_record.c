#include "ft_db.h"

int   delete_record(FILE *table, char *table_name)
{
  size_t     delete_line;
  size_t  line_count;
  size_t  getline_return;
  char    *record_entry;
  size_t  nbytes;
  FILE    *modified_table;

  modified_table = fopen("modified_table.csv", "w");
  nbytes = 100;
  line_count = 0;
  read_file(table);
  rewind(table);
  printf("Line to delete: ");
  scanf("%zu", &delete_line);
  printf("deleting line: %zu\n", delete_line);
  while (1)
  {
    if ((getline_return = getline(&record_entry, &nbytes, table)) !=
    strlen(record_entry))
      break ;
    if (line_count != delete_line)
      fprintf(modified_table, "%s", record_entry);
    line_count++;
  }
  fclose(table);
  fclose(modified_table);
  remove(table_name);
  rename("modified_table.csv", table_name);
//segfaults on exit of program
  return (1);
}
