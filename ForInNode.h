#ifndef FORINNODE_H_
#define FORINNODE_H_

#include "Node.h"
#include "Block.h"

typedef struct {
	Node node;
	char *var;
	Node *list;
	Block *block;
} ForInNode;

ForInNode *ForInNode_new(const char *var, Node *list, Block *block);
void ForInNode_delete(ForInNode *node);
_Object *ForInNode_eval(Node *node, Scope *scope);

#endif
