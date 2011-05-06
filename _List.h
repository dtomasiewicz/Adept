#ifndef _LIST_H_
#define _LIST_H_

#include "_Object.h"
#include "ArrayList.h"
#include <stdbool.h>

typedef struct {
	_Object obj;
	ArrayList *data;
} _List;

_List *_List_new();
void _List_delete(_List *list);
bool _List_test(_Object *obj);
void _List_set(_List *list, int index, void *value);
void *_List_get(_List *list, int index);
void _List_push(_List *list, void *value);
int _List_length(_List *list);

#endif
