#ifndef TOKENSET_H_
#define TOKENSET_H_

#include "LinkedList.h"
#include "Token.h"

typedef struct {
	LinkedList *tokens;
} TokenSet;

TokenSet *TokenSet_new();
void TokenSet_push(TokenSet *set, Token *token);
Token *TokenSet_shift(TokenSet *set);
Token *TokenSet_peek(TokenSet *set);
void TokenSet_delete(TokenSet *set);
int TokenSet_length(TokenSet *set);

#endif
