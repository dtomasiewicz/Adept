#ifndef UNNODE_H_
#define UNNODE_H_

#include "Node.h"
#include "_Object.h"

typedef struct {
	Node node;
	char *operator;
	Node *right;
} UnNode;

UnNode *UnNode_new(const char *operator, Node *right);
void UnNode_delete(UnNode *node);
_Object *UnNode_eval(Node *node, Scope *scope);

#endif
