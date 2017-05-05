/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolabi <yolabi@42.us.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 00:15:24 by yolabi            #+#    #+#             */
/*   Updated: 2017/05/05 16:02:42 by yolabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DB_H
# define FT_DB_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include "vector.h"
# include "t_list.h"

int			read_file(FILE *table);
char		*get_table_name(void);
int			add_record(vector *loaded_table);
int			del_record(vector *loaded_table);
void		delete_entry(FILE *table, char *delete_line);
int			modify_record(vector *loaded_table);
char		*attach_id(FILE *table);
t_list		*store_input(vector *loaded_table);
char		*itostr(int number);
int			read_table(FILE *table, vector *loaded_table);
void		display_loaded_table(vector *loaded_table);
void		*ft_memcpy(void *dest, const void *src, size_t n);
int			save_table(vector *loaded_table, char *table_name);
void		create_table(void);
void		help(void);
int			search_table(vector *loaded_table);

#endif
