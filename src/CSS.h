#ifndef CSS_H
#define CSS_H
#include <vector>
#include <string>
using namespace std;
class CSS 
{

    public:

        struct SimpleSelector {
            string tag_name;
            string id;
            vector<string> css_class;
        };

        enum Selector { SimpleSelector };

        enum Unit { Px };

        enum Value{ keyword, Unit };

        struct Color {
           int8_t r;
           int8_t g;
           int8_t b;
           int8_t a; 
        };

        struct Declaration {
            string name;
            Value value;
        };

        struct Rule {
            vector<Selector> selectors;
            vector<Declaration> declarations;
        };

        struct stylesheet {
            vector<Rule> rules;
        };




        CSS();
};

#endif