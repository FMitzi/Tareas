#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

/*
   Print List
*/

static void print_list (const List *list) {
    
	int i;
	ListNode *node;
    char *data;

    fprintf(stdout, "List size is %d\n", list_size(list));

    i = 0;
    node = list_head(list);

    while (1) {
        data = list_data(node);
        fprintf(stdout, "list.node[%03d]=%c, %p -> %p \n", i, *data, node, node->next);

        i++;

        if (list_is_tail(node))
            break;
        else
            node = list_next(node);
    }

   return;
}

void insert_at_head(List *list, char value){
	char *data=(char *)malloc(sizeof(char));
	
	if (data == NULL)
		return;//Si la asignación falla, ya no continúa
		
	*data = value;
	list_ins_next(list, NULL, data);
}

void insert_at_tail(List *list, char value){
	char *data = (char *)malloc(sizeof(char));
	
	if (data == NULL)
		return;
	
	*data = value;
	list_ins_next(list, list_tail(list), data);	
}

void insert_after_node(List *list, ListNode * node, char value){
	char *data = (char *)malloc(sizeof(char));
	
	if (data == NULL)
		return;
		
	*data =value;
	list_ins_next(list, node, data);	
}

void insert_at_position(List * list, int position, char value){
	int i;
	
	ListNode *node = list_head(list);
	
	for(i=0; i< position && node !=NULL; ++i)
		node=list_next(node);

	insert_after_node(list, node, value);
}

void remove_at_head(List *list){
	char *data;
	
	list_rem_next(list, NULL, (void**)&data);
	free(data);	
}

void remove_at_tail(List *list){
	ListNode *node=list_head(list);
	
	while (list_next(node) != list_tail(list)){
		node=list_next(node);
	}
	
	char *data;
	list_rem_next(list, node, (void**)&data);
	free(data);
}

void remove_after_node(List *list, ListNode *node){
	char *data;
	
	list_rem_next(list, node, (void**)&data);
	free(data);
}

void remove_at_position(List *list, int position){
	int i;
	
	ListNode *node=list_head(list);
	
	for(i=0; i<position-1 && node !=NULL; ++i)
		node=list_next(node);

	remove_after_node(list, node);
}

int main (int argc, char *argv[]) {
    List list;

    int i;
    char *num=argv[0];
    
    fprintf(stdout, "argv[0] = %s \n", argv[0]);
    
    // Initialize the linked list
     list_init(&list, free);

    // Insert elements from program arguments
    for (i = 1; i < argc; ++i) {
        insert_at_tail(&list, argv[i][0]);
    }

    print_list(&list);

    // Insert 'D' 'R' 'O' '9'
    insert_at_position(&list, 5, 'D');
    insert_at_tail(&list, 'R');
    insert_at_head(&list, 'O');
    insert_after_node(&list, list_head(&list), '9');
    
    print_list(&list);

    // Removing nodes from diff locations
    remove_at_head(&list);
    remove_at_tail(&list);
    remove_after_node(&list, list_head(&list));
    remove_at_position(&list, 3);

    print_list(&list);

    // Destroy the list
    fprintf(stdout, "\nDestroying the list\n");
    list_destroy(&list);

    return 0;
}
