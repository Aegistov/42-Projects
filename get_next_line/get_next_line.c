#include "get_next_line.h"
#include <stdio.h>

// char  *ft_charjoin(char const *s1, char c)
// {
//   char    *new_str;
//   size_t  len;
//   size_t  i;
//
//   i = -1;
//   if (!s1 || !c)
//     return (NULL);
//   len = ft_strlen(s1);
//   if (!(new_str = ft_strnew(len + 1)))
//     return (NULL);
//   ft_memcpy(new_str, s1, len);
//   *(new_str + len) = c;
//   free((void*)s1);
//   return (new_str);
// }

char  *consolidate(char *content, int start)
{
  size_t  len;
  char    *tmp;

  len = ft_strlen(content);
  tmp = (char *)ft_memalloc(len - start);
  while (content)
  {
    *tmp = content[start];
    tmp++;
    start++;
  }
  free(content);
  return (tmp);
}

int   load_single_line(char **dst, char *src, char c)
{
  int   i;
  int   j;

  j = 0;
  i = -1;
  while (src[++i])
  {
    if (src[i] == c)
      break ;
  }
  if (!(*dst = ft_strnew(i)))
    return (0);
  ft_memcpy(*dst, src, i);
  return (i);
}

int   get_next_line(const int fd, char **line)
{
  int           ret;
  char          buf[BUF_SIZE + 1];
  static char   **database;
  int           i;

  if (fd < 0 || line == NULL || read(fd, buf, 0) < 0)
    return (-1);
  if (!database)
    MALVER((database = (char**)ft_memalloc(sizeof(char *) * (MAX_FD + 1))));
  while ((ret = read(fd, buf, BUF_SIZE)))
  {
    buf[ret] = '\0';
    if (!database[fd])
      MALVER((database[fd] = (char*)ft_memalloc((BUF_SIZE + 1))));
    database[fd] = ft_strjoin(database[fd], buf);
    if (ft_strchr(buf, '\n'))
      break ;
  }
  if (ret < BUF_SIZE && !ft_strlen(database[fd]))
    return (0);
  i = load_single_line(line, database[fd], '\n');
  if (i < ft_strlen(database[fd]))
			{
        printf("[FORMER]:\n%s\n", database[fd][i+1]);
        consolidate(database[fd], i);
        printf("[consolidate]:\n%s\n", database[fd]);
      }
  else
    ft_strclr(database[fd]);
  return (1);
}
