#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>

enum TokenType { NUMBER, PLUS, MINUS, MUL, DIV, LPAREN, RPAREN, END };

struct Token {
    TokenType type;
    double value; // used if type == NUMBER
};

class Lexer {
public:
    explicit Lexer(const std::string& input);
    Token getNextToken();
private:
    std::string text;
    size_t pos;
    char currentChar;
    void advance();
    void skipWhitespace();
    double number();
};

#endif
