#include "Block.h"
#include "NodeSet.h"
#include "Scope.h"
#include "Lexer.h"
#include <stdlib.h>
#include <stdio.h>

Block *Block_new(FILE *fp, int fpos, int indent) {
	Block *block = malloc(sizeof(Block));
	block->fp = fp;
	block->fpos = fpos;
	block->indent = indent;
	return block;
}

void Block_delete(Block *block) {
	if(block->ops != NULL) {
		NodeSet_delete(block->ops);
	}
	free(block);
}

void Block_eval(Block *block, Scope *scope) {
	if(block->ops == NULL) {
		fseek(block->fp, block->fpos, SEEK_SET);
		block->ops = Parser_parse(Lexer_analyze(block));
	}
	NodeSet_eval(block->ops, scope);
}

int Block_eof(Block *block) {
	return feof(block->fp);
}

int Block_getc(Block *block) {
	return fgetc(block->fp);
}

void Block_ungetc(Block *block, int c) {
	ungetc(c, block->fp);
}

int Block_peekc(Block *block) {
	int c = fgetc(block->fp);
	ungetc(c, block->fp);
	return c;
}
