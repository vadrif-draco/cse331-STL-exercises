#include <iostream>
#include <queue>

void removeEvens(std::queue<int>& q) {

    int temp;
    int sz = q.size(); // Can't use q.size(); inside for loop while it changes every iteration!!
    for (int i = 0; i < sz; i++) {

        temp = q.front();
        q.pop();
        if (temp % 2 != 0) q.push(temp);

    }

}