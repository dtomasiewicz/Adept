#include "_Object.h"
#include "_String.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

_String *_String_new(const char *value) {
	_String *s = malloc(sizeof(_String));
	s->obj.type = String;
	s->obj.toString = &_String_toString;
	strcpy(s->val, value);
	s->length = strlen(s->val);
	return s;
}

void _String_delete(_String *string) {
	free(string);
}

bool _String_test(_Object *obj) {
	return obj->type == String;
}

_String *_String_toString(_Object *obj) {
	return (_String *) obj;
}
