#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_

typedef struct {
	int length;
	int size;
	void **data;
} ArrayList;

ArrayList *ArrayList_new(int initialSize);
void ArrayList_delete(ArrayList *list);
void ArrayList_set(ArrayList *list, int index, void *item);
void *ArrayList_get(ArrayList *list, int index);
int ArrayList_length(ArrayList *list);
int ArrayList_size(ArrayList *list);

#endif
