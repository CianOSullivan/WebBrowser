#include "Parser.h"

Parser::Parser(std::string input) {
    this->input = input;
}

char Parser::next_char() {
    return this->input[this->pos];
}

bool Parser::starts_with(std::string substring) {
    if (this->input.substr(this->pos).rfind(substring, 0) == 0) {
        return true;
    }
    return false;
}

bool Parser::eof() {
    return this->pos >= this->input.length();
}