/*
    main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "clist.h"

/* 
    Print the circular list
*/
static void print_list(const CList *list) {
    int i = 0;
    CListNode *node = clist_head(list);

    fprintf(stdout, "List size is %d\n", clist_size(list));
    if (clist_size(list) == 0) {
        fprintf(stdout, "The list is empty.\n");
        return;
    }

    do {
        fprintf(stdout, "list.node[%03d]=%d\n", i, *(int *)clist_data(node));
        node = clist_next(node);
        i++;
    } while (node != clist_head(list));
}

/* 
    Insert at the head of the circular list
*/
void insert_at_head(CList *list, int value) {
    int *data = (int *)malloc(sizeof(int));
    if (data == NULL) return;

    *data = value;
    if (clist_ins_next(list, clist_head(list) == NULL ? NULL : clist_head(list), data) != 0) {
        free(data);
    }
}

/* 
    Insert at the tail 
*/
void insert_at_tail(CList *list, int value) {
    int *data = (int *)malloc(sizeof(int));
    if (data == NULL) return;

    *data = value;
    if (clist_ins_next(list, clist_head(list) == NULL ? NULL : clist_head(list), data) != 0) {
        free(data);
    }
}

/* 
    Remove from the head 
*/
void remove_at_head(CList *list) {
    int *data;
    if (clist_rem_next(list, NULL, (void **)&data) == 0) {
        free(data);
    }
}

/* 
    Remove after a specific node
*/
void remove_after_node(CList *list, CListNode *node) {
    int *data;
    if (node != NULL && clist_rem_next(list, node, (void **)&data) == 0) {
        free(data);
    }
}

int main(int argc, char *argv[]) {
    CList list;
    int i, value;

    // Initialize the circular list
    clist_init(&list, free);

    // Insert elements from program arguments
    for (i = 1; i < argc; ++i) {
        value = atoi(argv[i]);
        insert_at_tail(&list, value);
    }

    print_list(&list);

    // Insertions
    insert_at_head(&list, 78);
    insert_at_tail(&list, 23);
    
    
    print_list(&list);

    // Removals
    remove_at_head(&list);

    print_list(&list);

    // Destroy the list
    fprintf(stdout, "Destroying the list\n");
    clist_destroy(&list);

    return 0;
}
