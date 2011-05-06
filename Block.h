#ifndef BLOCK_H_
#define BLOCK_H_

#include "Scope.h"
#include "TokenSet.h"
#include "NodeSet.h"
#include <stdio.h>

typedef struct {
	TokenSet *tokens;
	NodeSet *ops;
} Block;

Block *Block_new(TokenSet *tokens);
void Block_delete(Block *block);
void Block_eval(Block *block, Scope *scope);

#endif
