#ifndef VARNODE_H_
#define VARNODE_H_

#include "Node.h"
#include "_Object.h"

typedef struct {
	Node node;
	char *varName;
} VarNode;

VarNode *VarNode_new(const char *varName);
void VarNode_delete(VarNode *node);
_Object *VarNode_eval(Node *node, Scope *scope);

#endif
