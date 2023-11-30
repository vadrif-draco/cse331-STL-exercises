#include <iostream>
#include <queue>

template <typename T>
std::ostream& operator<<(std::ostream& out, std::queue<T> q) {

    for (int i = 0; i < q.size(); i++) {
        T temp = q.front();
        out << temp << ' ';
        q.pop();
        q.push(temp);
    }
    return out;

}

// Recall that if you write a template class or function in a separate file from where it is declared...
// ...then you need to explicitly instantiate classes or functions from this template
// Remember the analogy that a "template" document is a document awaiting you to customize it
// Again, this is done because the compiler needs to know what instances of this template class will be needed
// If you don't tell it, it won't create any classes from your "template" class

// Let's say I want to be able to print queues of ints, chars, and strings
template std::ostream& operator<<(std::ostream& out, std::queue<int> q);
template std::ostream& operator<<(std::ostream& out, std::queue<char> q);
template std::ostream& operator<<(std::ostream& out, std::queue<std::string> q);

// What the compiler does when you write the above lines is:
// It takes the generic data type "T" that you defined with "template <typename T>"...
// ...and replaces it with the data type you've written in the explicit instance
// Therefore, now you have three functions that each work on ints, chars, and strings
// But you only wrote a template function and told the compiler that you want three versions of it

// Note that if you try to use a data type that is incompatible with your logic.. for example, a class "X" you created...
// If you didn't implement the output operator for your class "X", then...
// When the compiler tries to create a function for this data type, it will fail and give you an error
// Here's the class X, if you try to use it without implementing its own operator<<, the compiler will fail
// Try it out! Uncomment the following two lines only..
// class X {};
// template std::ostream& operator<<(std::ostream& out, std::queue<X> q);

// However, if you implement the operator<< for the class X, it will work
// Here's a dummy implementation that does nothing, just returns the ostream
// Try it out! Uncomment it after uncommenting the previous two lines, and see if the compiler succeeds now..
// std::ostream& operator<<(std::ostream& out, X x) { return out; }