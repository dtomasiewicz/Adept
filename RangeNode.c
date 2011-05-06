#include "RangeNode.h"
#include "Scope.h"
#include "Node.h"
#include "_Integer.h"
#include "_List.h"
#include "_Object.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

RangeNode *RangeNode_new(Node *from, Node *to, bool inclusive) {
	RangeNode *node = malloc(sizeof(RangeNode));
	node->node.eval = &RangeNode_eval;
	node->from = from;
	node->to = to;
	node->inclusive = inclusive;
	return node;
}

void RangeNode_delete(RangeNode *node) {
	free(node);
}

// TODO: allow variables and characters to be used for TO and FROM
_Object *RangeNode_eval(Node *node, Scope *scope) {
	RangeNode *rNode = (RangeNode *)node;
	_Object *from = (_Object *)rNode->from->eval(rNode->from, scope);
	_Object *to = (_Object *)rNode->to->eval(rNode->to, scope);
	if(_Integer_test(from) && _Integer_test(to)) {
		int f = ((_Integer *)from)->val;
		int t = ((_Integer *)to)->val;
		int d, size;
		if(f <= t) {
			d = 1;
			size = t-f;
		} else {
			d = -1;
			size = f-t;
		}
		if(rNode->inclusive) {
			t += d;
			size += 1;
		}
		_List *list = _List_new(size);
		int i;
		for(i = f; i != t; i += d) {
			_List_push(list, _Integer_new(i));
		}
		return (_Object *)list;
	} else {
		return NULL;
	}
}
