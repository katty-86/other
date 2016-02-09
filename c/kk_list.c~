#include <stdio.h>
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
	n_node->prev = NULL;
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

void delete_element(list_t *list, void *data,int (*compareFunc)(void * x, void *y) ){
	int result;
	list_node_t *current=list->head;
	list_node_t *prev_current=list->head;
	
	if (list_size(list) == 0) {
		return;
	}
	while(current!=NULL){
		result=compareFunc(current->data, data);
		if(result){
			if(current==list->head){
				list->head=list->head->next;
				list->head->prev =NULL;
				free(current);
				list->size--;
				prev_current= list->head;
				current =list->head; 
			}else{
				prev_current->next=current->next;
				current->next->prev=prev_current;
				free(current);
				list->size--;
				current =prev_current->next;
				
			}
		}else{
			prev_current=current;
			current=current->next;
		}

		
		

	}	
	
}

void delete_from_tail(list_t *list){
	if (list_size(list) == 0) {
		return ;
	}
	if(list->head==list->tail){
		free(list->head);
		list->head=0;
		list->tail=0;
	}
	else{
		list->tail=list->tail->prev;
		free(list->tail->next);
		list->tail->next=0;		
	}
	list->size--;

}
/*dodaje element za jakims jesli rozmiar listy=0 dodaje jako pierwszy, jesli nie znajdzie dodaje na koniec*/
void add_element_after_val(list_t *list,void *data,  void *element, int (*compareFunc)(void * x, void *y) ){
	list_node_t *n_node;	
	list_node_t *current;
	list_node_t *next_current=list->head;
	int result, flag;
	flag =1;	
	
	if ((n_node = (list_node_t *) malloc(sizeof(list_node_t))) == NULL) {
		return;
	}
	n_node->data = (void *) element;
	n_node->next = NULL;
	n_node->prev = NULL;
	if (list_size(list) == 0) {
		list->head = list->tail = n_node;
	}
	current=list->head;
	while(current!=NULL && (flag==1)){
		result=compareFunc(current->data, data);
		if(result){
			if(current==list->head){
				next_current=list->head->next;
				list->head->next=n_node;
				n_node->next =next_current;
				next_current->prev=n_node;
				list->size++;
				flag=0; 
			}else{
				next_current=current->next;
				current->next=n_node;
				n_node->next =next_current;
				next_current->prev=n_node;
				list->size++;
				flag=0;
				
			}
		}else{
			current=current->next;
		}

	}
	if((current==NULL) &&(flag==1)){
		current=list->tail;
        	list->tail->next = n_node;
        	list->tail = n_node;
		list->tail->prev=current;
				
	}	

}
