int   modify_record(FILE *table, char *table_name)
{
  read_file(table);
  rewind(table);
  printf("Line to modify: ");
  scanf("%s", &modify_line);
}
