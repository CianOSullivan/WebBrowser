#ifndef PARSER_H
#define PARSER_H
#include <string>
#include <iostream>
#include <functional> // Required for std::function

class Parser
{
    public:
        Parser(std::string input);
        char next_char();
        bool starts_with(std::string substring);
        bool eof();
        char consume_char();
        std::string consume_while();
        void consume_whitespace();
        std::string parse_tag_name();



    private:
        size_t pos = 0;
        std::string input;

};
#endif