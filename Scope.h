#ifndef SCOPE_H_
#define SCOPE_H_

#include "Variable.h"
#include "LinkedList.h"

typedef struct SCOPE {
	struct SCOPE *parent;
	LinkedList *data;
} Scope;

Scope *Scope_new();
void Scope_delete(Scope *scope);
Variable *Scope_set(Scope *scope, const char *varName, void *value);
Variable *Scope_get(Scope *scope, const char *varName);
void Scope_unset(Scope *scope, const char *varName);

#endif
