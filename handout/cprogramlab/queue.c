/*
 * Code for basic C skills diagnostic.
 * Developed for courses 15-213/18-213/15-513 by R. E. Bryant, 2017
 */

/*
 * This program implements a queue supporting both FIFO and LIFO
 * operations.
 *
 * It uses a singly-linked list to represent the set of queue elements
 */

#include <stdlib.h>
#include <stdio.h>

#include "harness.h"
#include "queue.h"

/*
  Create empty queue.
  Return NULL if could not allocate space.
*/
queue_t *q_new()
{
    /* Remember to handle the case if malloc returned NULL */
    queue_t *queue = (queue_t *)malloc(sizeof(queue_t));
    if (queue == NULL) return NULL;
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
    return queue;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    /* Remember to free the queue structue and list elements */
    if (q == NULL) return;
    list_ele_t  *temp, *previous;
    for (temp = q->head; temp != NULL; temp= temp->next){
        previous = temp;
        q->head = temp->next;
        free(previous);
    }
    q->tail = NULL;
}

/*
  Attempt to insert element at head of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
 */
bool q_insert_head(queue_t *q, int v)
{
    /* What should you do if the q is NULL? */
    /* What if malloc returned NULL? */
    if (q == NULL) return false;
    list_ele_t *element = (list_ele_t *)malloc(sizeof(list_ele_t));
    if (element == NULL) return false;
    element->next = NULL;
    element->value = v;

    if (q->head == NULL){
        /* this is the first node in the list */
        q->head = element;
        q->tail = element;
        q->size = 1;
    }else{
        element->next = q->head;
        q->head = element;
        q->size ++;
    }
    return true;
}


/*
  Attempt to insert element at tail of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
 */
bool q_insert_tail(queue_t *q, int v)
{
    /* Remember: It should operate in O(1) time */
    if (q == NULL) return false;
    list_ele_t *element = (list_ele_t *)malloc(sizeof(list_ele_t));
    if(element == NULL) return false;
    element->next = NULL;
    element->value = v;

    if (q->tail == NULL){
        q->head = element;
        q->tail = element;
        q->size = 1;
    }else{
        q->tail->next = element;
        q->tail = element;
        q->size ++;
    }
    return false;
}

/*
  Attempt to remove element from head of queue.
  Return true if successful.
  Return false if queue is NULL or empty.
  If vp non-NULL and element removed, store removed value at *vp.
  Any unused storage should be freed
*/
bool q_remove_head(queue_t *q, int *vp)
{
    if (q == NULL || q->head == NULL) return false;
    list_ele_t *top;
    top = q->head;
    q->head = top->next;
    *vp = top->value;
    free(top);
    return true;
}

/*
  Return number of elements in queue.
  Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    /* Remember: It should operate in O(1) time */
    if (q == NULL || q->head == NULL) return 0;
    return q->size;
}

/*
  Reverse elements in queue.

  Your implementation must not allocate or free any elements (e.g., by
  calling q_insert_head or q_remove_head).  Instead, it should modify
  the pointers in the existing data structure.
 */
void q_reverse(queue_t *q)
{
    if (q == NULL) return;
    list_ele_t *previous, *temp, *next;
    previous = NULL;
    for (temp = q->head; temp != NULL;){
        next = temp->next;
        temp->next = previous;
        previous = temp;
        temp = next;
    }
    list_ele_t *head = q->head;
    q->head = q->tail;
    q->tail = head;
}

