#ifndef LEXER_H_
#define LEXER_H_

#include "TokenSet.h"
#include "Stream.h"

TokenSet *Lexer_analyze(Stream *code);

#endif
