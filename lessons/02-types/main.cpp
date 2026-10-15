#include <iostream>

int main()
{
    int total = 5;
    int count = 2;
    double decimalTotal = 5.0;

    std::cout << "int / int: " << total / count << '\n';
    std::cout << "double / int: " << decimalTotal / count << '\n';

    double result = total / count;
    std:: cout << "result: " << result << '\n'; // 2.0, 왜냐하면 reuslt가 double이나 int / int 계산에서 결과는 2, 해당 2를 double로 형변환한 결과.

    double a = static_cast<double>(total) / count;
    double b = static_cast<double>(total / count);


    std::cout << "a: " << a << '\n';
    // 2.5,
    // 계산 과정 : 5.0 / 2 = 2.5
    std::cout << "b: " << b << '\n';
    // 2.0 (표시는 2)
    // 계산 과정 : 5 / 2 = 2, 2 => 2.0


    int x = 3;
    // int y{3.7};

    std::cout << "x: " << x << '\n';
    // {} 초기화는 반올림 기능이 아님. 작은 변수형에 큰 변수를 담으로 했으므로 축소 변환 규칙에 어긋나므로 오류 발생, int < double
    return 0;
}
