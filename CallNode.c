#include "CallNode.h"
#include "Scope.h"
#include "Node.h"
#include "_String.h"
#include "_Object.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

CallNode *CallNode_new(const char *function, int argc, Node *argv[]) {
	CallNode *node = malloc(sizeof(CallNode));
	node->node.type = CALL;
	node->node.eval = &CallNode_eval;
	strcpy(node->function, function);
	node->argc = argc;
	node->argv = argv;
	return node;
}

void CallNode_delete(CallNode *node) {
	free(node);
}

// TODO: allow functions other than print to be called..
_Object *CallNode_eval(Node *node, Scope *scope) {
	CallNode *cNode = (CallNode *)node;
	if(cNode->argc > 0) {
		Node *arg1 = cNode->argv[0];
		_Object *obj = (_Object *)arg1->eval(arg1, scope);
		printf(obj->toString(obj)->val);
	} else {
		printf("ERROR: print() requires at least 1 argument.");
	}
	return NULL;
}
