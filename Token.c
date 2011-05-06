#include "Token.h"
#include <stdlib.h>
#include <string.h>

Token *Token_new(TokenType type, const char *value) {
	Token *token = malloc(sizeof(Token));
	token->type = type;
	token->value = malloc(strlen(value)+1);
	strcpy(token->value, value);
	return token;
}

void Token_delete(Token *token) {
	free(token);
}
