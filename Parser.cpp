#include "Parser.h"
#include <stdexcept>

Parser::Parser(Lexer& lexer) : lexer(lexer) {
    currentToken = lexer.getNextToken();
}

void Parser::eat(TokenType type) {
    if (currentToken.type == type) {
        currentToken = lexer.getNextToken();
    } else {
        throw std::runtime_error("Unexpected token");
    }
}

double Parser::factor() {
    if (currentToken.type == NUMBER) {
        double val = currentToken.value;
        eat(NUMBER);
        return val;
    } else if (currentToken.type == LPAREN) {
        eat(LPAREN);
        double val = expr();
        eat(RPAREN);
        return val;
    } else if (currentToken.type == MINUS) {
        eat(MINUS);
        return -factor();
    }
    throw std::runtime_error("Invalid factor");
}

double Parser::term() {
    double result = factor();
    while (currentToken.type == MUL || currentToken.type == DIV) {
        if (currentToken.type == MUL) {
            eat(MUL);
            result *= factor();
        } else {
            eat(DIV);
            result /= factor();
        }
    }
    return result;
}

double Parser::expr() {
    double result = term();
    while (currentToken.type == PLUS || currentToken.type == MINUS) {
        if (currentToken.type == PLUS) {
            eat(PLUS);
            result += term();
        } else {
            eat(MINUS);
            result -= term();
        }
    }
    return result;
}

double Parser::parse() {
    return expr();
}
