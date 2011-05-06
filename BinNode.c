#include "BinNode.h"
#include "_Object.h"
#include <stdlib.h>
#include <string.h>

BinNode *BinNode_new(Node *left, const char *operator, Node *right) {
	BinNode *node = malloc(sizeof(BinNode));
	node->node.type = BIN;
	node->node.eval = &BinNode_eval;
	node->left = left;
	strcpy(node->operator, operator);
	node->right = right;
	return node;
}

void BinNode_delete(BinNode *node) {
	free(node);
}

_Object *BinNode_eval(Node *node, Scope *scope) {
	//BinNode *bNode = (BinNode *)node;
	//_Object *left = bNode->left->eval(bNode->left, scope);
	//_Object *right = bNode->right->eval(bNode->right, scope);
	// TODO this
	return NULL;
}
