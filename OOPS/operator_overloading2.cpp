#include <iostream>
using namespace std;

class Count {
    private:
        int value;

   public:
    // constructor to initialize count to 5
    Count() : value(5) {}

    // overload ++ for prefix
    void operator++() {
        ++value;  // prefix increment
    }

    // overload ++ for postfix
    void operator++(int) {
        value++;  // postfix increment
    }

    void display() {
        cout << "Count: " << value << endl;
    }
};

int main() {
    Count count1;

    // call the "void operator++()" (prefix)
    ++count1;    // Prefix

    // call the "void operator++(int)" (postfix)
    count1++;    // Postfix

    count1.display();
    return 0;
}
