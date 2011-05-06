#include "_Object.h"
#include "_Integer.h"
#include "_String.h"
#include <stdlib.h>
#include <stdbool.h>

_Integer *_Integer_new(int value) {
	_Integer *i = malloc(sizeof(_Integer));
	i->obj.type = Integer;
	i->obj.toString = &_Integer_toString;
	i->val = value;
	return i;
}

void _Integer_delete(_Integer *integer) {
	free(integer);
}

bool _Integer_test(_Object *obj) {
	return obj->type == Integer;
}

_String *_Integer_toString(_Object *obj) {
	// todo convert to string properly
	return _String_new("{int}");
}
