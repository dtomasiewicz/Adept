#include "TokenSet.h"
#include "Token.h"
#include "LinkedList.h"
#include <stdlib.h>

TokenSet *TokenSet_new() {
	TokenSet *set = malloc(sizeof(TokenSet));
	set->tokens = LinkedList_new();
	return set;
}

void TokenSet_delete(TokenSet *set) {
	LinkedList_delete(set->tokens);
	free(set);
}

void TokenSet_push(TokenSet *set, Token *token) {
	LinkedList_push(set->tokens, (void *)token);
}

Token *TokenSet_shift(TokenSet *set) {
	return (Token *)LinkedList_shift(set->tokens);
}

int TokenSet_length(TokenSet *set) {
	return LinkedList_length(set->tokens);
}
