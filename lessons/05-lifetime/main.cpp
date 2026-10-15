#include <iostream>

struct Trace
{
    ~Trace()
    {
        std::cout << "D";
    }
};

int main()
{
    std::cout << "A";
    {
        Trace item;
        std::cout << "B";
    } // item is destroyed here; its destructor prints D.
    std::cout << "C\n";
}
