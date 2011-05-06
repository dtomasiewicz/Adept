#ifndef _INTEGER_H_
#define _INTEGER_H_

#include "_Object.h"
#include "_String.h"
#include <stdbool.h>

typedef struct {
	_Object obj;
	int val;
} _Integer;

_Integer *_Integer_new(int value);
void _Integer_delete(_Integer *integer);
bool _Integer_test(_Object *obj);
_String *_Integer_toString(_Object *obj);

#endif
