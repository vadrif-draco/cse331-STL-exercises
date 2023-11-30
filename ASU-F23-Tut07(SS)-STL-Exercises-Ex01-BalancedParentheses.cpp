#include <iostream>
#include <string>
#include <vector>

bool checkBalance(std::vector<char>& vector) {

    int balance = 0;
    std::vector<char>::iterator vector_iterator = vector.begin();
    while (vector_iterator != vector.end()) {
        if (*vector_iterator == '(') {
            balance++;
        } else if (*vector_iterator == ')') {
            if (balance == 0) return false;
            balance--;
        }
        vector_iterator++;
    }
    return (balance == 0);

}

// empty vector -- Valid
// (            -- Invalid
// )            -- Invalid
// ( (          -- Invalid
// ( )          -- Valid
// ) (          -- Invalid
// ) )          -- Invalid
// ( ( )        -- Invalid
// ( ) ) (      -- Invalid
// ( ( ) )      -- Valid
// ( ) ( )      -- Valid