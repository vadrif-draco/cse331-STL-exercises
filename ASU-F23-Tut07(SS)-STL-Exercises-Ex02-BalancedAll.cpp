#include <iostream>
#include <string>
#include <stack>

bool checkBalanceAll(std::string& str) {

    std::stack<int> st;
    for (int i = 0; i < str.length(); i++) {
        switch (str[i]) {
            case '<': st.push('>'); break;
            case '{': st.push('}'); break;
            case '[': st.push(']'); break;
            case '(': st.push(')'); break;
            case '>':
            case '}':
            case ']':
            case ')':
                if (st.empty()) return false;
                if (st.top() != str[i]) return false;
                st.pop();
                break;
        }
    }
    return st.empty(); // If empty, then all items have been matched.

}

// empty string -- Valid
// { ( [ ] ) }  -- Valid
// { } ( ) [ ]  -- Valid
// { ( } ) [ ]  -- Invalid
// { { { } }    -- Invalid
// { } } } }    -- Invalid
// ( ) < > }    -- Invalid