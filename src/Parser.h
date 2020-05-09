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
         * Get the node at the current position
         * 
         * @return the text or element node
         */
        Node parse_node();

        /**
         * Get the characters until a tag is reached
         * 
         * @return a text node
         */
        Node parse_text();
        
        /**
         * Get the Node for an element at the current position
         * 
         * @return an element node
         */
        Node parse_element();
        
        /**
         * Get the attributes of the current element node
         * 
         * @return the attribute name and value
         */
        std::map<std::string, std::string> parse_attr(); // Change this to a tuple?
        
        /**
         * Get the value of the current attribute
         * 
         * @return the value of the attribute
         */
        std::string parse_attr_value();
        
        /**
         * Combine all attributes for an element node into a map
         * 
         * @return the map of attributes for the element node
         */
        std::map<std::string, std::string> parse_attributes();
        
        /**
         * Parse all the nodes from the source
         * 
         * @return a vector of all nodes
         */
        std::vector<Node> parse_nodes();

        
        size_t pos = 0;     // The current position in the given string
        std::string input;  // The input HTML string

};
#endif