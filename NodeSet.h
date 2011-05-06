#ifndef NODESET_H_
#define NODESET_H_

#include "LinkedList.h"
#include "Scope.h"
#include "Node.h"

typedef struct {
	LinkedList *nodes;
} NodeSet;

NodeSet *NodeSet_new();
void NodeSet_push(NodeSet *set, Node *node);
Node *NodeSet_shift(NodeSet *set);
Node *NodeSet_peek(NodeSet *set);
int NodeSet_length(NodeSet *set);
void NodeSet_delete(NodeSet *set);
void NodeSet_eval(NodeSet *set, Scope *scope);

#endif
