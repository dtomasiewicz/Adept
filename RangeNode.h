#ifndef RANGENODE_H_
#define RANGENODE_H_

#include "Node.h"
#include "_Object.h"
#include <stdbool.h>

typedef struct {
	Node node;
	Node *from;
	Node *to;
	bool inclusive;
} RangeNode;

RangeNode *RangeNode_new(Node *from, Node *to, bool inclusive);
void RangeNode_delete(RangeNode *node);
_Object *RangeNode_eval(Node *node, Scope *scope);

#endif
