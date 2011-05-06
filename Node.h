#ifndef NODE_H_
#define NODE_H_

#include "Scope.h"

typedef enum {
	FORIN,
	BIN,
	UN,
	CALL,
	LIT,
	VAR
} NodeType;

typedef struct NODE {
	NodeType type;
	_Object *(*eval)(struct NODE *node, Scope *scope);
} Node;

#endif
