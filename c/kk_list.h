#ifndef KK_LIST_H_
#define KK_LIST_H_

#include <stdlib.h>

/* Struktura węzła listy jednokierunkowej */
typedef struct list_node_ {
	void *data;
	struct list_node_ *next;
	struct list_node_ *prev;
} list_node_t;

/* Struktura listy jednokierunkowej */

typedef struct list_{
	int size;
	int elementSize;
	list_node_t *head;
	list_node_t *tail;
} list_t;


void list_new(list_t *list, int elementSize);
void list_destroy(list_t *list); 
int list_size(list_t *list); 
void list_head(list_t *list, void *element);
void list_tail(list_t *list, void *element);
void list_append_end(list_t *list, void *data);
void add_element_after_val(list_t *list, void *data,  void *element, int (*compareFunc)(void * x, void *y) );
void delete_element(list_t *list, void *data, int (*compareFunc)(void *, void *) );
void delete_from_tail(list_t *list);

void print_list_back(list_t *list, void (*printFunc)(void *));
void print_list(list_t *list, void (*printFunc)(void *));



#endif /* KK_LIST_H_ */
