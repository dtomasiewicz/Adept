#ifndef CALLNODE_H_
#define CALLNODE_H_

#include "Node.h"
#include "_Object.h"

typedef struct {
	Node node;
	char *function;
	int argc;
	Node **argv;
} CallNode;

CallNode *CallNode_new(const char *function, int argc, Node *argv[]);
void CallNode_delete(CallNode *node);
_Object *CallNode_eval(Node *node, Scope *scope);

#endif
