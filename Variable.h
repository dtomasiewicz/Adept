#ifndef VARIABLE_H_
#define VARIABLE_H_

#include "_Object.h"

typedef struct {
	char *name;
	int hash;
	_Object *data;
} Variable;

Variable *Variable_new(const char *name, int hash, _Object *data);
void Variable_delete(Variable *var);
void Variable_set(Variable *var, _Object *value);
void *Variable_get(Variable *var);

#endif
