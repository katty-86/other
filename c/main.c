#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "kk_list.h"

#define LIST_SIZE  10
#define RAND_MAXVAL  50

void printInt(void *v){
	printf(" %d,",*(int *)v);
}

int comapareInt(void *x, void *y){
	int ix,iy;
	ix= *(int *)x;
	iy= *(int *)y;
	/*printf("ix %d iy %d \n",ix,iy);*/
	return (ix==iy)?1:0;
}

int main(void) {
	int i;
	list_t list;
	int head, tail; /*, randval;*/
	int val4, val0, val3;
	val4=4, val3=3,val0=0;
	list_new(&list, sizeof(int));
	srand(time(NULL));


	for(i=0; i<LIST_SIZE;i++){
		/*randval=rand()%RAND_MAXVAL; */
		list_append_end(&list, &i);
	}

	printf("*.Rozmiar :%d\n", list_size(&list));
	printf("*.Zawartość od głowy :\n");
	print_list(&list,printInt);
	printf("\n");
	printf("*.Zawartość od ogona :\n");
	print_list_back(&list,printInt);
	printf("\n");
	printf("*.Usuniecie 4:\n");
	delete_element(&list,(void*)&val4, comapareInt );
	print_list(&list,printInt);
	printf("\n");
	printf("*.Usuniecie 0:\n");
	delete_element(&list,(void*)&val0, comapareInt );
	print_list(&list,printInt);
	printf("\n");
	print_list_back(&list,printInt);
	printf("\n");
	printf("*.Usuniecie 2 razy ostatniego elementu:\n");
	delete_from_tail(&list);
	delete_from_tail(&list);
	print_list(&list,printInt);
	printf("\n");
	/*add_element_after_val(list,(void*)&val3,  (void*)&val4, comapareInt );*/
	printf("*.dodanie elementu 4 na koniec:\n");
	list_append_end(&list, &val4);
	print_list(&list,printInt);
	printf("\n");
	list_head(&list, (void *)&head);
	list_tail(&list, (void *)&tail);
	printf("*.glowa listy: %d,ogon listy: %d \n", head, tail);
	printf("*.Usuń liste:\n");
	list_destroy(&list);
	printf("*.Rozmiar :%d\n", list_size(&list));

	return EXIT_SUCCESS;
}

