#ifndef PARSER_H_
#define PARSER_H_

#include "NodeSet.h"
#include "TokenSet.h"

NodeSet *Parser_parse(TokenSet *tokens);
NodeSet *Parser_parseBlock(TokenSet *tokens, int indentLevel);

#endif
