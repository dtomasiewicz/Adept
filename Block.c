#include "Block.h"
#include "TokenSet.h"
#include "NodeSet.h"
#include "Scope.h"
#include <stdlib.h>
#include <stdio.h>

Block *Block_new(TokenSet *tokens) {
	Block *block = malloc(sizeof(Block));
	block->tokens = tokens;
	block->ops = NULL;
	return block;
}

void Block_delete(Block *block) {
	TokenSet_delete(block->tokens);
	if(block->ops != NULL) {
		NodeSet_delete(block->ops);
	}
	free(block);
}

void Block_eval(Block *block, Scope *scope) {
	if(block->ops == NULL) {
		block->ops = Parser_parse(block->tokens);
	}
	NodeSet_eval(block->ops, scope);
}
