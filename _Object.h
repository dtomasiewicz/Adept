#ifndef _OBJECT_H_
#define _OBJECT_H_

struct _STRING;

typedef struct _OBJECT {
	enum {Integer, List, String} type;
	struct _STRING *(*toString)(struct _OBJECT *);
} _Object;

struct _STRING *_Object_toString(_Object *);

#endif
