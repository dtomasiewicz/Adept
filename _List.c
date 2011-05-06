#include "_List.h"
#include "ArrayList.h"
#include "_Object.h"
#include <stdlib.h>
#include <stdbool.h>

_List *_List_new(int size) {
	_List *list = malloc(sizeof(_List));
	list->obj.toString = &_Object_toString; //todo: proper toString
	list->data = ArrayList_new(size);
	return list;
}

void _List_delete(_List *list) {
	ArrayList_delete(list->data);
	free(list);
}

bool _List_test(_Object *obj) {
	return obj->type == List;
}

void _List_set(_List *list, int index, void *value) {
	ArrayList_set(list->data, index, value);
}

void *_List_get(_List *list, int index) {
	return ArrayList_get(list->data, index);
}

void _List_push(_List *list, void *value) {
	_List_set(list, _List_length(list), value);
}

int _List_length(_List *list) {
	return list->data->length;
}
