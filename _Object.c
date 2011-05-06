#include "_Object.h"
#include "_String.h"

_String *_Object_toString(_Object *obj) {
	//todo this properly
	return _String_new("{obj}");
}
