#include <stack>
#include <iostream>
using namespace std;


string convertToBinary(unsigned number) {

    stack<unsigned> stackOfRemainders;
    string result;

    if (number == 0) stackOfRemainders.push(0);

    while (number != 0) {
        stackOfRemainders.push(number % 2);
        number /= 2;
    }

    while (!stackOfRemainders.empty()) {
        result += '0' + stackOfRemainders.top();
        stackOfRemainders.pop();
    }

    return result;

}
