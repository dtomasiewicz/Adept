#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

typedef struct LINKED_LIST_NODE {
	struct LINKED_LIST_NODE *next;
	struct LINKED_LIST_NODE *prev;
	void *data;
} LinkedListNode;

typedef struct {
	LinkedListNode *head;
	LinkedListNode *tail;
	LinkedListNode *ptr;
	int length;
} LinkedList;

LinkedList *LinkedList_new();
void LinkedList_delete(LinkedList *list);
void LinkedList_push(LinkedList *list, void *item);
void LinkedList_unshift(LinkedList *list, void *item);
void *LinkedList_pop(LinkedList *list);
void *LinkedList_shift(LinkedList *list);
void *LinkedList_peek(LinkedList *list);
int LinkedList_length(LinkedList *list);
void *LinkedList_iterate(LinkedList *list);
void LinkedList_reset(LinkedList *list);

#endif
