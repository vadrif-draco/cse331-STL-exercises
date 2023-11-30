#include <iostream>
#include <string>
#include <stack>
#include <queue>

bool checkPalindrome(std::string& str) {

    std::stack<int> stack;
    std::queue<int> queue;
    for (int i = 0; i < str.length(); i++) {
        stack.push(str[i]);
        queue.push(str[i]);
    }

    for (int i = 0; i < str.length() / 2; i++) {
        if (stack.top() != queue.front()) return false;
        stack.pop();
        queue.pop();
    }
    return true;

}