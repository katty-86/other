#include <stdlib.h>
#include "kk_list.h"
#include <string.h>

void list_new(list_t *list, int elementSize){
    list->size=0;
    list->elementSize=elementSize;
    list->head=list->tail=NULL;
}


int list_size(list_t *list){
    return list->size;
}


void list_destroy(list_t *list){
	list_node_t *current;
	while(list->head!=NULL){
		current=list->head;
		list->head=current->next;
		free(current->data);
		free(current);
		list->size--;
	}

}


void list_head(list_t *list, void *element){
	
	list_node_t *current= list->head;	
	if(list->head==NULL){
		return;
	}

	memcpy(element, current->data, list->elementSize);

}


void list_tail(list_t *list, void *element){
	
	list_node_t *current= list->tail;	
	if(list->head==NULL){
		return;
	}

	memcpy(element, current->data, list->elementSize);

}
void list_append_end(list_t *list, void *data){
	list_node_t *n_node;
	list_node_t *p_node=NULL;
	
	if((n_node=malloc(sizeof(list_node_t)))==NULL){
		return;
	}
        n_node->data = malloc(list->elementSize);
        n_node->next = NULL;
  	memcpy(n_node->data, data, list->elementSize);
	

        if(list->size == 0) {
       		list->head = list->tail = n_node;
        } else {
		p_node=list->tail;
        	list->tail->next = n_node;
        	list->tail = n_node;
		list->tail->prev=p_node;
        }
	list->size++;
}

void print_list(list_t *list, void (*printFunc)(void *)){
	list_node_t *current= list->head;
	if(list->head==NULL){
		return;
	}
	while(current!=NULL){
		(*printFunc)(current->data);
		current=current->next;
	
	}
}


void print_list_back(list_t *list, void (*printFunc)(void *)){
	list_node_t *current= list->tail;
	if(list->head==NULL){
		return;
	}
	while(current!=NULL){
		(*printFunc)(current->data);
		current=current->prev;
	
	}
}

int delete_element(list_t *list,void *data, int (*compareFunc)(void * x, void *y) ){
	int result=0;
	list_node_t *current;
	while(list->head!=NULL &&result){
		printf("test");
		result=0;
	}
	
	return 1;	
}
