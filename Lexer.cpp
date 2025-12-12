#include "Lexer.h"
#include <cctype>

Lexer::Lexer(const std::string& input) : text(input), pos(0) {
    currentChar = pos < text.size() ? text[pos] : '\0';
}

void Lexer::advance() {
    pos++;
    currentChar = pos < text.size() ? text[pos] : '\0';
}

void Lexer::skipWhitespace() {
    while (currentChar != '\0' && isspace(currentChar)) advance();
}

double Lexer::number() {
    std::string result;
    while (currentChar != '\0' && (isdigit(currentChar) || currentChar == '.')) {
        result += currentChar;
        advance();
    }
    return std::stod(result);
}

Token Lexer::getNextToken() {
    while (currentChar != '\0') {
        if (isspace(currentChar)) { skipWhitespace(); continue; }
        if (isdigit(currentChar)) return {NUMBER, number()};
        if (currentChar == '+') { advance(); return {PLUS, 0}; }
        if (currentChar == '-') { advance(); return {MINUS, 0}; }
        if (currentChar == '*') { advance(); return {MUL, 0}; }
        if (currentChar == '/') { advance(); return {DIV, 0}; }
        if (currentChar == '(') { advance(); return {LPAREN, 0}; }
        if (currentChar == ')') { advance(); return {RPAREN, 0}; }
        throw std::runtime_error("Invalid character");
    }
    return {END, 0};
}
