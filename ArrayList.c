#include "ArrayList.h"
#include <stdlib.h>
#define ARRAY_LIST_EXPAND 2

ArrayList *ArrayList_new(int initialSize) {
	ArrayList *list = malloc(sizeof(ArrayList));
	list->data = calloc(initialSize, sizeof(void *));
	list->size = initialSize;
	list->length = 0;
	return list;
}

void ArrayList_delete(ArrayList *list) {
	free(list->data);
	free(list);
}

void ArrayList_expand(ArrayList *list, int targetSize) {
	int size = list->size > 0 ? list->size : 1;
	while(size < targetSize) {
		size *= ARRAY_LIST_EXPAND;
	}
	list->data = realloc(list->data, size * sizeof(void *));
	list->size = size;
}

void ArrayList_set(ArrayList *list, int index, void *item) {
	if(index >= 0) {
		if(index >= list->size) {
			ArrayList_expand(list, index + 1);
		}
		if(index >= list->length) {
			int i;
			for(i = list->length; i < index; i++) {
				list->data[index] = NULL;
			}
			list->length = index + 1;
		}
		list->data[index] = item;
	}
}

void *ArrayList_get(ArrayList *list, int index) {
	if(index >= 0 && index < list->length) {
		return list->data[index];
	}
	return NULL;
}

int ArrayList_length(ArrayList *list) {
	return list->length;
}

int ArrayList_size(ArrayList *list) {
	return list->size;
}
