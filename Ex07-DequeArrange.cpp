#include <deque>

void banishTheNegativity(int* nums, int size) {

    std::deque<int> dq;
    for (int i = 0; i < size; i++) {

        if (nums[i] < 0) {
            dq.push_back(nums[i]);
        } else {
            dq.push_front(nums[i]);
        }

    }

    int temp;
    for (int i = size - 1; i >= 0; i--) {

        temp = dq.back();
        if (temp < 0) {
            dq.pop_back();
        } else {
            temp = dq.front();
            dq.pop_front();
        }
        nums[i] = temp;

    }
}