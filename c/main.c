#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include "kk_list.h"

#define LIST_SIZE  10
#define RAND_MAXVAL  50

void printInt(void *v){
	printf(" %d,",*(int *)v);
}

int printInt(void *v, void *y){
	int ix,iy;
	ix= *(int *)x;
	iy= *(int *)y;
	return (ix==iy)?0:1
}

int main(void) {
	int i;
	list_t list;
	int head, tail, randval, val;
	list_new(&list, sizeof(int));
	srand(time(NULL));


	for(i=0; i<LIST_SIZE;i++){
		randval=rand()%RAND_MAXVAL;
		list_append_end(&list, &randval);
	}

	printf("*.Rozmiar :%d\n", list_size(&list));
	printf("*.Zawartość od głowy :\n");
	print_list(&list,printInt);
	printf("\n");
	printf("*.Zawartość od ogona :\n");
	print_list_back(&list,printInt);
	printf("\n");
	list_head(&list, (void *)&head);
	list_tail(&list, (void *)&tail);
//	delete_element(&list,(void*)&val, int (*compareFunc)(void *, void) )
	printf("*.glowa listy: %d,ogon listy: %d \n", head, tail);
	printf("*.Usuń liste:\n");
	list_destroy(&list);
	printf("*.Rozmiar :%d\n", list_size(&list));

	return EXIT_SUCCESS;
}

