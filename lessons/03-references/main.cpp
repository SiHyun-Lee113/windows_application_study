#include <iostream>

int main()
{
    int a{10};
    int b{20};
    int& r = a;

    std::cout << "1) a=" << a << ", b=" << b << ", r=" << r << '\n';

    r = b;
    std::cout << "2) a=" << a << ", b=" << b << ", r=" << r << '\n';

    b = 30;
    std::cout << "3) a=" << a << ", b=" << b << ", r=" << r << '\n';

    std::cout << "same_object=" << (&r == &a) << '\n';
    return 0;
}
