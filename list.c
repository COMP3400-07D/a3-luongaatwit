#include "list.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * Returns the head of the linked list.
 * 
 * @param head Pointer to the first node of the linked list.
 * @return The head of the linked list. If the list is empty (NULL), returns NULL.
 */
struct ll_node *ll_head(struct ll_node *head) {
    return head;
}

/**
 * Returns The Tail of the linked list 
 */
struct ll_node *ll_tail(struct ll_node *head) {
    if (head == NULL) {
        return NULL;
    }

    struct ll_node *node = head; 
    while (node ->next != NULL) {
       node = node -> next;
    }
    return node;
    
}

/**
 * Return the number of nodes in the linked list 
 */
int ll_size(struct ll_node *head) {
  int count = 0;
  struct ll_node *node = head;
  while (node != NULL) { 
    count++;
    node = node -> next;
  }
  return count; 
}

/**
 * find node in a linked list 
 */
struct ll_node *ll_find(struct ll_node *head, int value) {
    struct ll_node *node = head;
    while ( node != NULL) { 
        if (node->data  == value) {
            return node;
            node = node -> next;
        }
    }
   return NULL;
}

/**
 * Takes a Linked list and changes into an array
 */
int *ll_toarray(struct ll_node *head) {
   int size = ll_size(head);
   if (size == 0 ) { 
    return NULL;
   }

   int *arr = malloc(size *sizeof(int));
   if (arr == NULL) {
    return NULL;
   }

   struct ll_node *node = head;
   for (int i = 0; i < size; i++) {
    arr[i] = node -> data;
    node = node -> next;
   }
   
   return arr;

}

/**
 * Create a new linked list wtih given data 
 */
struct ll_node *ll_create(int data) {
   struct ll_node *node = malloc(sizeof(struct ll_node));
   if (node == NULL) {
    return NULL;
   }
   node -> data = data;
   node -> next = NULL;
   return node; 
}

/**
 * frees all nodes in the linked list
 */
void ll_destroy(struct ll_node *head) {
    struct ll_node *node  =  head; 
    while ( node != NULL) {
        struct ll_node *next = node -> next;
        free(node);
        node = next;
    }
}

/**
 *  Appends new node with given value to the end of the linked list 
 * 
 */ 
 void ll_append(struct ll_node *head, int data) {

 if( head == NULL) {
    return; 
 }

 struct ll_node *tail = ll_tail(head);
 tail -> next  = ll_create(data);

}

/**
 * Creates linked list from a interger array 
 */
struct ll_node *ll_fromarray(int* data, int len) {
if (data == NULL || len <= 0 ) { 
    return NULL;
}
struct ll_node *head = ll_create(data[0]) ; 
struct ll_node *tail = head; 

for (int i = 1 ; i < len ; i++) { 
    tail -> next = ll_create (data[i]); 
    tail = tail -> next;
}
return head; 
}

/**
 * destroys a single node 
 */
struct ll_node *ll_remove(struct ll_node *head, int value) {

    if ( head == NULL) { 
        return NULL;
    }

    if (head -> data == value) { 
        struct ll_node *new_head = head -> next;
        free(head); 
        return new_head;
    }

    struct ll_node *prev = head;
    struct ll_node *curr = head -> next; 

    while (curr != NULL) { 
        if ( curr -> data == value) {
            prev -> next = curr -> next; 
            free(curr);
            break;
        }
        prev = curr;
        curr = curr -> next; 
    }
    return head; 

}

