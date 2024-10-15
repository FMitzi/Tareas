#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

/* 
Print List 
*/
static void print_list(const DList *list) {
    int i = 0;
    DListNode *node = dlist_head(list);
    
    fprintf(stdout, "List size is %d\n", dlist_size(list));
    while (node != NULL) {
        fprintf(stdout, "list.node[%03d]=%d, %p <-> %p\n", i, *(int *)dlist_data(node), dlist_prev(node), dlist_next(node));
        node = dlist_next(node);
        i++;
    }
}

/* 
Insert at head 
*/
void insert_at_head(DList *list, int value) {
    int *data = (int *)malloc(sizeof(int));
    if (data == NULL) return;

    *data = value;
    dlist_ins_prev(list, dlist_head(list), data);
}

/* 
Insert at tail 
*/
void insert_at_tail(DList *list, int value) {
    int *data = (int *)malloc(sizeof(int));
    if (data == NULL) return;

    *data = value;
    dlist_ins_next(list, dlist_tail(list), data);
}

/* 
Insert after a specific node
*/
void insert_after_node(DList *list, DListNode *node, int value) {
    int *data = (int *)malloc(sizeof(int));
    if (data == NULL) return;

    *data = value;
    dlist_ins_next(list, node, data);
}

/* 
Insert at a specific position
*/
void insert_at_position(DList *list, int position, int value) {
    DListNode *node = dlist_head(list);
    int i;

    for (i = 0; i < position && node != NULL; i++) {
        node = dlist_next(node);
    }

    if (node == NULL) {
        insert_at_tail(list, value);  // Si la posición es mayor al tamaño de la lista, inserta al final.
    } else {
        insert_after_node(list, node, value);
    }
}

/* 
Remove from head 
*/
void remove_at_head(DList *list) {
    int *data;
    if (dlist_remove(list, dlist_head(list), (void **)&data) == 0) {
        free(data);
    }
}

/* 
Remove from tail 
*/
void remove_at_tail(DList *list) {
    int *data;
    if (dlist_remove(list, dlist_tail(list), (void **)&data) == 0) {
        free(data);
    }
}

/* 
Remove after a specific node
*/
void remove_after_node(DList *list, DListNode *node) {
    int *data;
    if (node != NULL && dlist_remove(list, dlist_next(node), (void **)&data) == 0) {
        free(data);
    }
}

/* 
Remove at a specific position
*/
void remove_at_position(DList *list, int position) {
    DListNode *node = dlist_head(list);
    int i;

    for (i = 0; i < position && node != NULL; i++) {
        node = dlist_next(node);
    }

    if (node != NULL) {
        int *data;
        dlist_remove(list, node, (void **)&data);
        free(data);
    }
}

int main(int argc, char *argv[]) {
    DList list;
    int i, value;

    // Initialize the double linked list
    dlist_init(&list, free);

    // Insert elements from program arguments
    for (i = 1; i < argc; ++i) {
        value = atoi(argv[i]);
        insert_at_tail(&list, value);
    }

    print_list(&list);

    //Insertions
     
    insert_at_head(&list, 60);        
    insert_at_tail(&list, 30);
	insert_at_position(&list, 5, 12);         

    print_list(&list);

    //Removals
    remove_at_head(&list);             
    remove_at_position(&list, 3); 
	remove_at_tail(&list);      

    print_list(&list);

    // Destroy the list
    fprintf(stdout, "Destroying the list\n");
    dlist_destroy(&list);

    return 0;
}

