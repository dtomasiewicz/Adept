#include "NodeSet.h"
#include "Scope.h"
#include "LinkedList.h"
#include "Node.h"
#include <stdlib.h>

NodeSet *NodeSet_new() {
	NodeSet *set = malloc(sizeof(NodeSet));
	set->ins = LinkedList_new();
	return set;
}

void NodeSet_delete(NodeSet *set) {
	LinkedList_delete(set->ins);
	free(set);
}

void NodeSet_eval(NodeSet *set, Scope *scope) {
	Node *current;
	while(NULL != (current = (Node *)LinkedList_iterate(set->ins))) {
		current->eval(current, scope);
	}
}
