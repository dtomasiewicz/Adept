#include "Variable.h"
#include <stdlib.h>
#include <string.h>

Variable *Variable_new(const char *name, int hash, _Object *data) {
	Variable *var = malloc(sizeof(Variable));
	strcpy(var->name, name);
	var->hash = hash;
	var->data = data;
	return var;
}

void Variable_delete(Variable *var) {
	free(var);
}

void Variable_set(Variable *var, _Object *value) {
	var->data = value;
}

void *Variable_get(Variable *var) {
	return var->data;
}
