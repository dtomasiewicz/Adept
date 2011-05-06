#include "LitNode.h"
#include "_Object.h"
#include <stdlib.h>
#include <string.h>

LitNode *LitNode_new(const char *literal) {
	LitNode *node = malloc(sizeof(LitNode));
	node->node.type = LIT;
	node->node.eval = &LitNode_eval;
	strcpy(node->literal, literal);
	return node;
}

void LitNode_delete(LitNode *node) {
	free(node);
}

_Object *LitNode_eval(Node *node, Scope *scope) {
	//LitNode *lNode = (LitNode *)node;
	// todo: parse literal to object
	return NULL;
}
