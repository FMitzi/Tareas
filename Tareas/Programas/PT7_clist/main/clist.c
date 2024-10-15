/*
    clist.c
*/

#include <stdlib.h>
#include <string.h>
#include "clist.h"

/*
    Initialize the circular list
*/
void clist_init(CList *list, void (*destroy)(void *data)) {
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;

    return;
}

/*
    Destroy the circular list
*/
void clist_destroy(CList *list) {
    void *data;

    while (clist_size(list) > 0) {
        if (clist_rem_next(list, NULL, (void **)&data) == 0 && list->destroy != NULL) {
            list->destroy(data);
        }
    }
    memset(list, 0, sizeof(CList));
    return;
}

/*
    Insert the next node in the circular list
*/
int clist_ins_next(CList *list, CListNode *node, const void *data) {
    CListNode *new_node;

    
    if ((new_node = (CListNode *)malloc(sizeof(CListNode))) == NULL)
        return -1;

    new_node->data = (void *)data;

    if (clist_size(list) == 0) {
        
        new_node->next = new_node;
        list->head = new_node;
    } else {
        
        new_node->next = node->next;
        node->next = new_node;
    }

    
    list->size++;
    return 0;
}

/*
    Remove the next node from the circular list
*/
int clist_rem_next(CList *list, CListNode *node, void **data) {
    CListNode *old_node;

    
    if (clist_size(list) == 0)
        return -1;

    
    if (node == NULL) {
       
        *data = list->head->data;
        if (clist_size(list) == 1) {
            
            old_node = list->head;
            list->head = NULL;
        } else {
            old_node = list->head;
            node = list->head;
            while (node->next != list->head) {
                node = node->next;
            }
            node->next = list->head->next;
            list->head = list->head->next;
        }
    } else {
        
        old_node = node->next;
        *data = old_node->data;
        node->next = old_node->next;
    }

    
    free(old_node);

    list->size--;
    return 0;
}
