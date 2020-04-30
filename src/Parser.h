#ifndef PARSER_H
#define PARSER_H
#include <string>
#include <iostream>
#include <map> // Required for maps
#include <assert.h>
#include "Node.h"

class Parser
{
    public:
    // Should be private?
        Parser(std::string input);
        char next_char();
        bool starts_with(std::string substring);
        bool eof();
        char consume_char();
        std::string consume_while();
        void consume_whitespace();
        std::string parse_tag_name();
        Node parse_node();
        Node parse_text();
        Node parse_element();
        std::map<std::string, std::string> parse_attr(); // Change this to a tuple?
        std::string parse_attr_value();
        std::map<std::string, std::string> parse_attributes();
        std::vector<Node> parse_nodes();

        // Should be public
        Node parse(std::string source);

    private:
        size_t pos = 0;
        std::string input;

};
#endif