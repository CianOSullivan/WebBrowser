#include "Parser.h"
using namespace std;
Parser::Parser() {}

char Parser::next_char() {
    return input[pos];
}

bool Parser::starts_with(string substring) {
    if (input.substr(pos).rfind(substring, 0) == 0) {
        return true;
    }
    return false;
}

bool Parser::eof() {
    // Check if the end of file is reached
    return pos >= input.length();
}

char Parser::consume_char() {
    // Return the current character
    char current = input[pos];
    pos += 1;
    return current;
}

void Parser::consume_whitespace() {
    // Consume only whitespace characters
    while (!eof() && isspace(next_char())) {
        consume_char();
    }
}

string Parser::parse_tag_name() {
    // Consume only alphanumeric characters
    string result;
    while (!eof() && isalnum(next_char())) {
        result += consume_char();
    }

    return result;
}

Node Parser::parse_node() {
    if (next_char() == '<') {
         return parse_element();
    } else {
        return parse_text();
    }
}

Node Parser::parse_text() {
    string nodeText;
    // Consume while not equal to <
    while (!eof() && (next_char() != '<')) {
        nodeText += consume_char();
    }
    // Return the node with the parsed text
    Node node(nodeText);
    return node;
}

Node Parser::parse_element() {
    // Opening tag
    assert(consume_char() == '<');
    string name = parse_tag_name();
    map<string, string> attrs = parse_attributes();
    assert(consume_char() == '>');
    
    // Contents
    vector<Node> children = parse_nodes();
    
    // Closing tag
    assert(consume_char() == '<');
    assert(consume_char() == '/');
    assert(parse_tag_name() == name);
    assert(consume_char() == '>');

    Node node(name, attrs, children);
    return node;
}

map<string, string> Parser::parse_attr() {
    string name = parse_tag_name();
    assert(consume_char() == '=');
    string value = parse_attr_value();

    map<string, string> attr;
    attr.insert(pair<string, string>(name, value));
    return attr;
}

string Parser::parse_attr_value() {
    char open_quote = consume_char();
    assert(open_quote == '"' || open_quote == '\'');
    string value;

    // Consume while not equal to "
    while (!eof() && (next_char() != open_quote)) {
        value += consume_char();
    }
    assert(consume_char() == open_quote);

    return value;
}

map<string, string> Parser::parse_attributes() {
    map<string, string> attributes;

    while (true) {
        consume_whitespace();
        if (next_char() == '>') {
            break;
        }
        attributes.insert(parse_attr().begin(), parse_attr().end()); // Maybe make this more efficient?
    }

    return attributes;
}

vector<Node> Parser::parse_nodes() {
    vector<Node> nodes;
    while (true) {
        consume_whitespace();

        if (eof() || starts_with("</")) {
            break;
        }

        nodes.push_back(parse_node());
    }

    return nodes;
}

Node Parser::parse(string source) {
    input = source;
    vector<Node> nodes = parse_nodes();

    if (nodes.size() == 1) {
        return nodes[0]; // This may not work
    } else {
        map<string, string> attributes;
        Node rootNode("html", attributes, nodes);
        return rootNode;
    }
}
