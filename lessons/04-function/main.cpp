#include <iostream>

int makeValue() {
    int value = 42;

    return value; // 이 시점에서 전달한 값은 value의 주소가 아닌 값, 즉 42이다.
}

int main() {

    int answer = makeValue();

    std::cout << "answer: " << answer << '\n'; // answer에 담겨 있는 값이 value의 주소가 아닌 값이기 때문에 value와 상관이 없음. 안전.

    return 0;
}
