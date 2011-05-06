#ifndef LEXER_H_
#define LEXER_H_

#include "TokenSet.h"
#include "Block.h"

TokenSet *Lexer_analyze(Block *code);

#endif
