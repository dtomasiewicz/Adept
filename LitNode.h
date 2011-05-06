#ifndef LITNODE_H_
#define LITNODE_H_

#include "Node.h"
#include "_Object.h"

typedef struct {
	Node node;
	char *literal;
} LitNode;

LitNode *LitNode_new(const char *literal);
void LitNode_delete(LitNode *node);
_Object *LitNode_eval(Node *node, Scope *scope);

#endif
