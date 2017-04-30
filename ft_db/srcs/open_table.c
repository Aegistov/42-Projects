#include "ft_db.h"

char  *open_table(void)
{
  char	*table_name;
  char	*tmp;

  table_name = (char *) malloc(2000);
  printf("Table Name: ");
  scanf("%s", table_name);
  // printf("1\n");
  tmp = (char *) malloc(strlen(table_name));
  tmp = strcpy(tmp, table_name);
  free(table_name);
  // printf("2\n");
  return (tmp);
}
