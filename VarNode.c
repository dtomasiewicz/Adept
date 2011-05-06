#include "VarNode.h"
#include "_Object.h"
#include <stdlib.h>
#include <string.h>

VarNode *VarNode_new(const char *varName) {
	VarNode *node = malloc(sizeof(VarNode));
	node->node.type = VAR;
	node->node.eval = &VarNode_eval;
	strcpy(node->varName, varName);
	return node;
}

void VarNode_delete(VarNode *node) {
	free(node);
}

_Object *VarNode_eval(Node *node, Scope *scope) {
	VarNode *vNode = (VarNode *)node;
	return Scope_get(scope, vNode->varName)->data;
}
