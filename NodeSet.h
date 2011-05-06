#ifndef NODESET_H_
#define NODESET_H_

#include "LinkedList.h"
#include "Scope.h"

typedef struct {
	LinkedList *ins;
} NodeSet;

NodeSet *NodeSet_new();
void NodeSet_delete(NodeSet *set);
void NodeSet_eval(NodeSet *set, Scope *scope);

#endif
