#include "NodeSet.h"
#include "Scope.h"
#include "LinkedList.h"
#include "Node.h"
#include <stdlib.h>

NodeSet *NodeSet_new() {
	NodeSet *set = malloc(sizeof(NodeSet));
	set->nodes = LinkedList_new();
	return set;
}

void NodeSet_delete(NodeSet *set) {
	LinkedList_delete(set->nodes);
	free(set);
}

void NodeSet_eval(NodeSet *set, Scope *scope) {
	Node *current;
	while(NULL != (current = (Node *)LinkedList_iterate(set->nodes))) {
		current->eval(current, scope);
	}
}

void NodeSet_push(NodeSet *set, Node *Node) {
	LinkedList_push(set->nodes, (void *)Node);
}

Node *NodeSet_shift(NodeSet *set) {
	return (Node *)LinkedList_shift(set->nodes);
}

Node *NodeSet_peek(NodeSet *set) {
	return (Node *)LinkedList_peek(set->nodes);
}

int NodeSet_length(NodeSet *set) {
	return LinkedList_length(set->nodes);
}
