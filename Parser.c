#include "Parser.h"
#include "TokenSet.h"
#include "NodeSet.h"
#include "Token.h"
#include "Node.h"
#include "ForInNode.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 * Finishes the logical line. Handles logical line breaks and end-of-line
 * whitespace and comments.
 */
void Parser_finishLine(TokenSet *tokens, int indentLevel) {
	// skipspace
	// check for semi
	//   yes? skipspace, unshift appropriate indent, return
	//   no? check for comment
	//     yes? remove comment, remove pline, return
	//     no? check for pline
	//       yes? remove pline, return
	//       no? error: more data is on logical line than expected
}

void Parser_errUnexpected(TokenType found, TokenType expected) {
	printf("PARSE ERROR: Unexpected TokenType::%d, expecting TokenType::%d\n", found, expected);
	exit(EXIT_FAILURE);
}

void Parser_errIndent(int found, int expected) {
	printf("PARSE ERROR: Unexpected indentation level of %d, expecting %d\n", found, expected);
	exit(EXIT_FAILURE);
}

void Parser_skipSpace(TokenSet *tokens) {
	Token *t = TokenSet_peek(tokens);
	if(t->type == SPACE) {
		TokenSet_shift(tokens);
	}
}

void Parser_skipSpaceAndComment(TokenSet *tokens) {
	Parser_skipSpace(tokens);
	Token *t = TokenSet_peek(tokens);
	if(t->type == COMMENT) {
		TokenSet_shift(tokens);
	}
}

Node *Parser_expression(TokenSet *tokens) {
	//@todo: this
	return NULL;
}

Node *Parser_for(TokenSet *tokens, int indentLevel) {
	Parser_skipSpace(tokens);
	Token *t = TokenSet_shift(tokens);
	if(t->type == WORD) {
		Parser_skipSpace(tokens);

		Token *in = TokenSet_shift(tokens);
		if(in->type != IN) {
			Parser_errUnexpected(in->type, IN);
			return NULL;
		}

		Node *expr = Parser_expression(tokens);

		Parser_skipSpaceAndComment(tokens);

		Token *eol = TokenSet_shift(tokens);
		if(eol->type != PLINE) {
			Parser_errUnexpected(eol->type, PLINE);
			return NULL;
		}

		return (Node *)ForInNode_new(
			t->value, expr, Parser_parseBlock(tokens, indentLevel+1));
	} else {
		Parser_errUnexpected(t->type, WORD);
		return NULL;
	}
}

NodeSet *Parser_parseBlock(TokenSet *tokens, int indentLevel) {
	NodeSet *nodes = NodeSet_new();
	while(TokenSet_length(tokens) > 0) { // each indent represents a physical line
		Token *indent = TokenSet_peek(tokens);
		int lineIndent;
		if(indent->type == SPACE) {
			lineIndent = strlen(indent->value);
			TokenSet_shift(tokens);
		} else {
			lineIndent = 0;
		}
		if(lineIndent < indentLevel) {
			return nodes;
		} else if(lineIndent > indentLevel) {
			Parser_errIndent(indentLevel, lineIndent);
		} else {
			Token *t = TokenSet_shift(tokens);
			switch(t->type) {
				case FOR:
					NodeSet_push(nodes, Parser_for(tokens, indentLevel));
					break;
				default:
					NodeSet_push(nodes, Parser_expression(tokens));
					break;
			}
		}
	}
	return nodes;
}

NodeSet *Parser_parse(TokenSet *tokens) {
	return Parser_parseBlock(tokens, 0);
}
