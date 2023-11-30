// Write your implementations in this file and test them one by one
// If you want to run my solutions instead, each exercise is solved in its respective file
// To compile them all at once, g++ <all the files in this folder>, which can be done with regex: g++ *.cpp
// On Visual Studio, simply place all the .cpp files in the same project; as "source" files
// But, please, try to write them on your own first. The tester functions should help guide you.

#include <iostream>
#include <queue>
#include <map>
using namespace std;

// --- Exercise 01:
// You are given a vector that contains parentheses (the '(' and ')' characters)
// Find if it is balanced, i.e., for every '(', there exists a ')' in that order
// Use a vector iterator in your logic instead of looping over vector.size()
bool checkBalance(vector<char>&);

// --- Exercise 02:
// Alright let's make this more difficult. How about instead of '(' and ')', you also check: '{', '}', '<', '>', '[', ']'?
// Different types of brackets must open and close in order (for example, <{>} is invalid even though each bracket is closed)
// Given the brackets in the form of a string, use an STL stack to solve it
bool checkBalanceAll(string& str);

// --- Exercise 03:
// Use a stack to convert an unsigned number into its binary form and print it
string convertToBinary(unsigned);

// --- Exercise 04:
// Remember the checkPalindrome function that we implemented in Tut 05? Probably not.
// Anyway, now you should implement it with stacks and queues!
bool checkPalindrome(std::string&);

// --- Exercise 05:
// Overload the output operator for printing a templated STL queue
template <typename T>
ostream& operator<<(ostream&, queue<T>);

// --- Exercise 06:
// Given a queue with even and odd values, you are required to remove even values from it.
// WITHOUT using a new queue or stack or anything. And WITHOUT changing the order.
void removeEvens(queue<int>&);

// --- Exercise 07:
// Remember Ex05 from Tut02? No of course you don't.
// This function takes an array of integers, and its size.
// It is required to move all positive values to the beginning,
// and all the negative values to the end, while maintaining their order, both.
// Ex: { 0, 9, -7, 2, -12, 11, -20 } -> { 0, 9, 2, 11, -7, -12, -20 }
// Back in Tut02, I told you there's a possible implementation with a "deque".
// Now that you know what a "deque" is, can you do it?
void banishTheNegativity(int* nums, int size);

// --- Exercise 08:
// Watch out, big chungus exercise coming up
// In this function, you are required to parse the provided colors.json file into an STL map container
// You will need to open the colors.json file to see how it is structured, then using string methods to parse it
// You will also need fstream (file stream) to open the file and read its contents
// Trust me, it's worth the effort!
std::map<string, string> parseColorsJson(std::string filename);

// Tester functions (you don't need to implement any of these, only run them to test your implementation)
void testEx01(void);
void testEx02(void);
void testEx03(void);
void testEx04(void);
void testEx05(void);
void testEx06(void);
void testEx07(void);
void testEx08(void);

int main() {

    // Makes cout print true and false for bool values instead of 1 and 0
    boolalpha(cout);

    // Uncomment each test when you implement its functionality
    // testEx01();
    // testEx02();
    // testEx03();
    // testEx04();
    // testEx05();
    // testEx06(); // Make sure you've completed ex05 before trying to test ex06
    // testEx07();
    // testEx08();

    return 0;
}

void testEx01(void) {

    cout << "\n---------- Exercise 1 -----------\n";

    // The "pair" data type is used to create a two-element container of any datatypes
    // Here, I am using it to contain:
    // 1. A vector of characters for the test case
    // 2. A boolean for the expected result from the test case
    // You can access each item of the pair using ".first" and ".second" members
    vector<pair<vector<char>, bool>> testCases(
        {
            {{' '}, true}, // Valid
            {{'('}, false}, // Invalid
            {{')'}, false}, // Invalid
            {{'(', '('}, false}, // Invalid
            {{'(', ')'}, true}, // Valid
            {{')', '('}, false}, // Invalid
            {{')', ')'}, false}, // Invalid
            {{'(', '(', ')'}, false}, // Invalid
            {{'(', ')', ')', '('}, false}, // Invalid
            {{'(', '(', ')', ')'}, true}, // Valid
            {{'(', ')', '(', ')'}, true} // Valid
        }
    );
    for (pair<vector<char>, bool> testCase : testCases) {
        cout << "Test case:\t";
        for (char c : testCase.first) cout << c << ' ';
        cout << "\nYour result:\t" << checkBalance(testCase.first);
        cout << "\nExpected:\t" << testCase.second;
        cout << endl << endl;
    }

}

void testEx02(void) {

    cout << "\n---------- Exercise 2 -----------\n";

    vector<pair<string, bool>> testCases(
        {
            {"empty string", true}, // Valid
            {"{([])}", true}, // Valid
            {"{3+5}(2-1)[4]", true}, // Valid
            {"{(})[]", false}, // Invalid
            {"{{{hi}}", false}, // Invalid
            {"{bye}}}", false}, // Invalid
            {"{([how])[<[are]>[you]?]}", true}, // Valid
        }
    );
    for (pair<string, bool> testCase : testCases) {
        cout << "Test case:\t" << testCase.first;
        cout << "\nYour result:\t" << checkBalanceAll(testCase.first);
        cout << "\nExpected:\t" << testCase.second;
        cout << endl << endl;
    }

}

void testEx03(void) {

    cout << "\n---------- Exercise 3 -----------\n";

    vector<pair<unsigned, string>> testCases(
        {
            {0, "0"},
            {1, "1"},
            {2, "10"},
            {3, "11"},
            {4, "100"},
            {412, "110011100"},
        }
    );
    for (pair<unsigned, string> testCase : testCases) {
        cout << "Test case:\t" << testCase.first;
        cout << "\nYour result:\t" << convertToBinary(testCase.first);
        cout << "\nExpected:\t" << testCase.second;
        cout << endl << endl;
    }

}

void testEx04(void) {

    cout << "\n---------- Exercise 4 -----------\n";

    vector<pair<string, bool>> testCases(
        {
            {"racecar", true},
            {"abba", true},
            {"aaa", true},
            {"aa", true},
            {"a", true},
            {"no", false},
            {"", true},
        }
    );
    for (pair<string, bool> testCase : testCases) {
        cout << "Test case:\t" << testCase.first;
        cout << "\nYour result:\t" << checkPalindrome(testCase.first);
        cout << "\nExpected:\t" << testCase.second;
        cout << endl << endl;
    }

}

void testEx05(void) {

    cout << "\n---------- Exercise 5 -----------\n";
    queue<int> q({ 61, 21, 33, 14, 55 });
    vector<int> v({ 61, 21, 33, 14, 55 });

    cout << "Test case:\t";
    for (int c : v) cout << c << ' ';
    cout << endl;

    cout << "Your result:\t" << q << endl;

    cout << "Expected:\t";
    for (int c : v) cout << c << ' ';
    cout << endl;

}

void testEx06(void) {

    cout << "\n---------- Exercise 6 -----------\n";

    queue<int> q({ 1, 2, 4, 8, 3, -5, 11, -4, 3, 2, -1 });
    cout << "Test case:\t" << q << endl;

    removeEvens(q);
    cout << "Your result:\t" << q << endl;

    queue<int> ans({ 1, 3, -5, 11, 3, -1 });
    cout << "Expected:\t" << ans << endl;

}

void testEx07(void) {

    cout << "\n---------- Exercise 7 -----------\n";

    int nums[] = { 0, 9, -7, 2, -12, 11, -20 };
    int size = sizeof(nums) / sizeof(nums[0]);

    cout << "Test case:\t";
    for (int i = 0; i < size; i++) cout << nums[i] << ' ';
    cout << endl;

    banishTheNegativity(nums, size);
    cout << "Your result:\t";
    for (int i = 0; i < size; i++) cout << nums[i] << ' ';
    cout << endl;

    int ans[] = { 0, 9, 2, 11, -7, -12, -20 };
    cout << "Expected:\t";
    for (int i = 0; i < size; i++) cout << ans[i] << ' ';
    cout << endl;

}

void testEx08(void) {

    cout << "\n---------- Exercise 8 -----------\n";

    map<string, string> myColorsMap = parseColorsJson("colors.json");

    vector<pair<string, string>> testCases = {
        {"#9ACD32", "YellowGreen"},
        {"#F0F8FF", "AliceBlue"},
        {"#32CD32", "LimeGreen"},
        {"#B8860B", "DarkGoldenRod"},
    };
    for (pair<string, string> testCase : testCases) {
        cout << "Test case:\t" << testCase.first;
        cout << "\nYour result:\t" << myColorsMap[testCase.first];
        cout << "\nExpected:\t" << testCase.second;
        cout << endl << endl;
    }

}