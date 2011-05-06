#ifndef _STRING_H_
#define _STRING_H_

#include "_Object.h"
#include <stdbool.h>

typedef struct _STRING {
	_Object obj;
	char *val;
	int length;
} _String;

_String *_String_new(const char *val);
void _String_delete(_String *string);
bool _String_test(_Object *obj);
_String *_String_toString(_Object *obj);

#endif
