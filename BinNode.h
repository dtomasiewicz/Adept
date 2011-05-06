#ifndef BINNODE_H_
#define BINNODE_H_

#include "Node.h"
#include "_Object.h"

typedef struct {
	Node node;
	Node *left;
	char *operator;
	Node *right;
} BinNode;

BinNode *BinNode_new(Node *left, const char *operator, Node *right);
void BinNode_delete(BinNode *node);
_Object *BinNode_eval(Node *node, Scope *scope);

#endif
