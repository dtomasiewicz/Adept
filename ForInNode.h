#ifndef FORINNODE_H_
#define FORINNODE_H_

#include "Node.h"
#include "NodeSet.h"

typedef struct {
	Node node;
	char *var;
	Node *list;
	NodeSet *block;
} ForInNode;

ForInNode *ForInNode_new(const char *var, Node *list, NodeSet *block);
void ForInNode_delete(ForInNode *node);
_Object *ForInNode_eval(Node *node, Scope *scope);

#endif
