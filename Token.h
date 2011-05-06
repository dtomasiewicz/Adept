#ifndef TOKEN_H_
#define TOKEN_H_

typedef enum {
	DEFAULT, // not an actual token type
	SPACE,   // space or tab
	PLINE,   // physical line break

	// words: fit ^[a-zA-Z_][a-zA-Z_0-9]*$

	// reserved words
	FOR,     // for
	ROF,     // end of for
	IN,      // in
	WHILE,   // while
	ELIHW,   // end of while
	DEF,     // def
	FED,     // end of def
	CLASS,   // class
	SSALC,   // end of class
	IF,      // if
	FI,      // end of if
	ELSEIF,  // elseif
	ELSE,    // else

	// any other word-- variable, constant, class/function name, etc.
	WORD,

	// expression grouping / flow control
	COMMA,   // ,
	SEMI,    // ;
	POPEN,   // (
	PCLOSE,  // )
	BROPEN,  // {
	BRCLOSE, // }
	SQOPEN,  // [
	SQCLOSE, // ]

	// LITERALS
	LSTRING, // string literal
	LINTEGER,// integer literal
	LFLOAT,  // float literal
	LTRUE,   // true literal
	LFALSE,  // false literal
	LNULL,   // null literal

	COMMENT,

	// anything else is an operator (or syntax error)
	OPERATOR
} TokenType;

typedef struct {
	TokenType type;
	char *value;
} Token;

Token *Token_new(TokenType type, const char *value);
void Token_delete(Token *token);

#endif
