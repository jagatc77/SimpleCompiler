#ifndef PARSER_H
#define PARSER_H

#include "Lexer.h"

class Parser {
public:
    explicit Parser(Lexer& lexer);
    double parse();
private:
    Lexer& lexer;
    Token currentToken;
    void eat(TokenType type);
    double expr();
    double term();
    double factor();
};

#endif
