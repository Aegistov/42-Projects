/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 16:48:24 by mmorel            #+#    #+#             */
/*   Updated: 2017/05/05 16:48:26 by mmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# define VECTOR_INIT_CAPACITY 100

# define VECTOR_INIT(vec) vector vec; vector_init(&vec)
# define VECTOR_ADD(vec, item) vector_add(&vec, (void *) item)
# define VECTOR_SET(vec, id, item) vector_set(&vec, id, (void *) item)
# define VECTOR_GET(vec, type, id) (type) vector_get(&vec, id)
# define VECTOR_DELETE(vec, id) vector_delete(&vec, id)
# define VECTOR_TOTAL(vec) vector_total(&vec)
# define VECTOR_FREE(vec) vector_free(&vec)

typedef	struct 	vector
{
	void	**items;
	int		capacity;
	int		total;	
}				vector;

void			vector_init(vector *);
int				vector_total(vector *);
void			vector_resize(vector *, int);
void			vector_add_list(vector *, void *);
void			vector_set(vector *, int, void *);
void			*vector_get(vector*, int);
void			vector_delete(vector *, int);
void			vector_free(vector *);

#endif
