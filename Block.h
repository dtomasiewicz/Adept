#ifndef BLOCK_H_
#define BLOCK_H_

#include "Scope.h"
#include "NodeSet.h"
#include <stdio.h>

typedef struct {
	FILE *fp;
	int fpos;
	int indent;
	NodeSet *ops;
} Block;

Block *Block_new();
void Block_delete(Block *block);
void Block_eval(Block *block, Scope *scope);
int Block_eof(Block *block);
int Block_getc(Block *block);
void Block_ungetc(Block *block, int c);
int Block_peekc(Block *block);

#endif
