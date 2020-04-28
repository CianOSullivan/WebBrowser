#ifndef PARSER_H
#define PARSER_H
#include <string>

class Parser
{
    public:
        Parser(std::string input);
        char next_char();
        bool starts_with(std::string substring);
        bool eof();

    private:
        size_t pos;
        std::string input;

};
#endif