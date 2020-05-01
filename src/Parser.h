#ifndef PARSER_H
#define PARSER_H
#include <string>
#include <iostream>
#include <map> // Required for maps
#include <assert.h>
#include "Node.h"

/** @brief The Parser class.

    This class parses a given html input string into a DOM tree
    
    @author Cian O'Sullivan
    */
class Parser
{
    public:
        /**
         * Make a new HTML parser
         */ 
        Parser();

        /**
         * Generate the DOM tree witht the given input
         * 
         * @param source the input HTML
         * @return the root node to the DOM tree
         */
        Node parse(std::string source);

    private:
        char next_char();

        /**
         * Determines whether the current position in the input file starts 
         * with the given substring
         * 
         * @param substring the string being checked against
         * @return whether the current string starts with the substring
         */
        bool starts_with(std::string substring);

        /**
         * Shows eof status
         * 
         * @return whether we are at the end of the input
         */
        bool eof();

        /**
         * Get the current character and increase position
         * 
         * @returns the current character
         */
        char consume_char();

        /**
         * Consume whitespace until a non-whitespace character is reached
         */
        void consume_whitespace();
        
        /**
         * Consume until a non-alphanumeric character is reached
         * 
         * @return the name of the tag
         */
        std::string parse_tag_name();
        
        /**
         * 
         */
        Node parse_node();

        /**
         * 
         */
        Node parse_text();
        
        /**
         * 
         */
        Node parse_element();
        
        /**
         * 
         */
        std::map<std::string, std::string> parse_attr(); // Change this to a tuple?
        
        /**
         * 
         */
        std::string parse_attr_value();
        
        /**
         * 
         */
        std::map<std::string, std::string> parse_attributes();
        
        /**
         * 
         */
        std::vector<Node> parse_nodes();

        
        size_t pos = 0;     // The current position in the given string
        std::string input;  // The input HTML string

};
#endif