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

char Parser::consume_char() {
    char current = this->input[this->pos];
    pos += 1;
    return current;
}

std::string Parser::consume_while() {
    std::string result;
    while (!eof()) {
        result += consume_char();
    }

    return result;
}

void Parser::consume_whitespace() {
    std::string result;
    while (!eof() && isspace(next_char())) {
        result += consume_char();
    }
}

std::string Parser::parse_tag_name() {
    std::string result;
    // consume only alphanumeric characters
    while (!eof() && isalnum(next_char())) {
        result += consume_char();
    }

    return result;
}