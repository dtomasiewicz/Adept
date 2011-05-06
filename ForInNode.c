#include "ForInNode.h"
#include "_List.h"
#include "Variable.h"
#include "Scope.h"
#include "Node.h"
#include "_Object.h"
#include "NodeSet.h"
#include <stdlib.h>
#include <string.h>

ForInNode *ForInNode_new(const char *var, Node *list, NodeSet *block) {
	ForInNode *node = malloc(sizeof(ForInNode));
	node->node.type = FORIN;
	node->node.eval = &ForInNode_eval;
	strcpy(node->var, var);
	node->list = list;
	node->block = block;
	return node;
}

void ForInNode_delete(ForInNode *node) {
	free(node);
}

_Object *ForInNode_eval(Node *node, Scope *scope) {
	ForInNode *fiNode = (ForInNode *)node;
	_List *items = fiNode->list->eval(fiNode->list, scope);
	Variable *_x = Scope_set(scope, fiNode->var, NULL);
	int i;
	for(i = 0; i < _List_length(items); i++) {
		Variable_set(_x, (_Object *)_List_get(items, i));
		Block_eval(fiNode->block, scope);
	}
	return NULL;
}
