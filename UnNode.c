#include "UnNode.h"
#include "_Object.h"
#include <stdlib.h>
#include <string.h>

UnNode *UnNode_new(const char *operator, Node *right) {
	UnNode *node = malloc(sizeof(UnNode));
	node->node.type = UN;
	node->node.eval = &UnNode_eval;
	strcpy(node->operator, operator);
	node->right = right;
	return node;
}

void UnNode_delete(UnNode *node) {
	free(node);
}

_Object *UnNode_eval(Node *node, Scope *scope) {
	//UnNode *uNode = (UnNode *)node;
	//_Object *right = uNode->right->eval(uNode->right, scope);
	// TODO this
	return NULL;
}
