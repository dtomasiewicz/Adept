#include "Scope.h"
#include "hash.h"
#include "Variable.h"
#include <stdlib.h>

Scope *Scope_new(Scope *parent) {
	Scope *scope = malloc(sizeof(Scope));
	scope->parent = parent;
	scope->data = LinkedList_new();
	return scope;
}

void Scope_delete(Scope *scope) {
	while(LinkedList_length(scope->data) > 0) {
		Variable_delete(LinkedList_pop(scope->data));
	}
	LinkedList_delete(scope->data);
	free(scope);
}

Variable *Scope_set(Scope *scope, const char *varName, void *value) {
	Variable *var = Variable_new(varName, hashString(varName), value);
	LinkedList_push(scope->data, var);
	return var;
}

Variable *Scope_get(Scope *scope, const char *varName) {
	int hash = hashString(varName);
	Variable *current;
	LinkedList_reset(scope->data);
	while(NULL != (current = (Variable *)LinkedList_iterate(scope->data))) {
		if(current->hash == hash) {
			return current;
		}
	}
	return NULL;
}
