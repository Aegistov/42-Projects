#define MENU  																\
	printf("Welcome to the DBMS\n\n");										\
	printf("Please listen closely, as our menu options have changed:\n");	\
	printf("Enter a selection number.\n");									\
	printf("1 - Select Database.\n");										\
	printf("2 - Select Table\n");											\
	printf("3 - Display Table\n");											\
	printf("4 - Add to Table\n")

#define CURR_OPTS															\
	printf("current options:\n");											\
	if(strlen(db_name))														\
		printf("Selected DB: %s\n", db_name);								\
	if(strlen(t_name))														\
		printf("Selected table: %s\n", t_name);\
	printf("\n")

/*
**	LIMITATIONS OF FT_DB IMPLEMENTATION
**
**
**
**
**
**
**
**
*/

#include "ft_db.h"

int main (void)//int argc, char **argv)
{
	int menu_opt;
	char db_name[DBNAME_SIZE];
	char t_name[TNAME_SIZE];
//	char **fields;
	FILE *fp;
	char *line[1000];
	size_t len = 0;
	size_t bytes_read;
	menu_opt = 10;
	while (menu_opt != 0)
	{
		MENU;
		CURR_OPTS;
		scanf("%d", &menu_opt);

		if (menu_opt == 1)
		{
			printf("Please enter a database name: ");
			scanf("%s",db_name);
			printf("Selected DB: %s\n", db_name);
		}
		else if (menu_opt == 2)
		{
			printf("Please enter a table name: ");
			scanf("%s",t_name);
			printf("Selected table: %s\n", t_name);
		}
		else if (menu_opt == 3)
		{
			fp = fopen(strcat(db_name, t_name), "r");
			while ((bytes_read = read(fp, line, 10)))
			{
				printf("Retrieved line of length %zu :\n", bytes_read);
				printf("%s", line);
			}
		}

	}
	return (0);
}
