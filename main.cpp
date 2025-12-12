#include "Lexer.h"
#include "Parser.h"
#include <iostream>
#include <string>

int main() {
    std::cout << "Enter an arithmetic expression: ";
    std::string input;
    std::getline(std::cin, input);

    try {
        Lexer lexer(input);
        Parser parser(lexer);
        double result = parser.parse();
        std::cout << "Result: " << result << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
