#include "LinkedList.h"
#include <stdlib.h>

LinkedListNode *LinkedListNode_new(void *data, LinkedListNode *next,
    LinkedListNode *prev) {
	LinkedListNode *node = malloc(sizeof(LinkedListNode));
	node->next = next;
	node->prev = prev;
	node->data = data;
	return node;
}

void LinkedListNode_delete(LinkedListNode *node) {
	free(node);
}

LinkedList *LinkedList_new() {
	LinkedList *list = malloc(sizeof(LinkedList));
	list->head = NULL;
	list->tail = NULL;
	list->ptr = NULL;
	list->length = 0;
	return list;
}

void LinkedList_delete(LinkedList *list) {
	LinkedListNode *current = list->head;
	while(current != NULL) {
		LinkedListNode_delete(current);
	}
	free(list);
}

void LinkedList_push(LinkedList *list, void *item) {
	list->tail = LinkedListNode_new(item, NULL, list->tail);
	if(list->tail->prev != NULL) {
		list->tail->prev->next = list->tail;
	}
	if(list->head == NULL) {
		list->head = list->tail;
	}
	list->length++;
}

void LinkedList_unshift(LinkedList *list, void *item) {
	list->head = LinkedListNode_new(item, list->head, NULL);
	if(list->head->next != NULL) {
		list->head->next->prev = list->head;
	}
	if(list->tail == NULL) {
		list->tail = list->head;
	}
	list->length++;
}

void *LinkedList_pop(LinkedList *list) {
	LinkedListNode *ret = list->tail;
	if(NULL != ret) {
		if(NULL != (list->tail = ret->prev)) {
			list->tail->next = NULL;
		}
		if(ret == list->head) {
			list->head = NULL;
		}
		if(list->ptr == ret) {
			list->ptr = NULL;
		}
		list->length--;
		return ret->data;
	}
	return NULL;
}

void *LinkedList_shift(LinkedList *list) {
	LinkedListNode *ret = list->head;
	if(NULL != ret) {
		if(NULL != (list->head = ret->next)) {
			list->head->prev = NULL;
		}
		if(ret == list->tail) {
			list->tail = NULL;
		}
		if(list->ptr == ret) {
			list->ptr = NULL;
		}
		list->length--;
		return ret->data;
	}
	return NULL;
}

void *LinkedList_peek(LinkedList *list) {
	if(list->head == NULL) {
		return NULL;
	} else {
		return list->head->data;
	}
}

int LinkedList_length(LinkedList *list) {
	return list->length;
}

void *LinkedList_iterate(LinkedList *list) {
	if(list->ptr == NULL) {
		list->ptr = list->head;
	} else {
		list->ptr = list->ptr->next;
	}
	return list->ptr == NULL ? NULL : list->ptr->data;
}

void LinkedList_reset(LinkedList *list) {
	list->ptr = NULL;
}
