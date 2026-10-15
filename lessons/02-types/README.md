# 1-2. 타입과 제어 흐름 — 첫 수업: 타입과 숫자 연산

이번 목표는 변수의 타입을 읽고, 정수 나눗셈과 실수 나눗셈의 결과를 설명하는 거야. Windows와 macOS에서 사용할 수 있는 표준 C++ 예제야.

## 변수 선언과 초기화

```cpp
int total = 5;
double decimalTotal = 5.0;
```

`int`는 정수를, `double`은 부동소수점 수를 다루는 타입이야. `total`과 `decimalTotal`은 변수 이름이고, 이 두 선언의 `=`는 변수를 만들면서 초기값을 지정하는 초기화에 사용됐어. 이미 있는 변수의 값을 바꾸는 대입과 구분해두자.

## Dart와 비교하기

아래 표는 기본 숫자 타입의 연산을 비교한 거야.

| 언어 | 표현식 | 결과 | 결과 타입 |
| --- | --- | --- | --- |
| Dart | `5 / 2` | `2.5` | `double` |
| Dart | `5 ~/ 2` | `2` | `int` |
| C++ | `5 / 2` | `2` | `int` |
| C++ | `5.0 / 2` | `2.5` | `double` |

C++에서 정수끼리 `/` 연산하면 소수 부분을 버린 정수 몫을 구해. 음수까지 포함하면 0을 향해 잘라내는 규칙이야. 반올림하는 게 아니야. 이번 예제처럼 한쪽이 `double`이고 다른 쪽이 `int`면 `double`로 변환한 뒤 실수 나눗셈을 수행해.

## 실행하기

Windows에서는 [types.vcxproj](types.vcxproj)를 Visual Studio 2022의 **파일 → 열기 → 프로젝트/솔루션**으로 열어. **Debug / x64**를 확인하고 **Ctrl+F5**로 빌드·실행해. [main.cpp](main.cpp)는 이 프로젝트의 유일한 소스 파일이야.

예상 출력:

```text
int / int: 2
double / int: 2.5
```

Windows에서 Developer PowerShell로 직접 빌드하려면 이 폴더에서 다음 명령을 실행해.

```powershell
New-Item -ItemType Directory -Path build -Force | Out-Null
cl /nologo /EHsc /std:c++17 /W4 /Zi /Od main.cpp /Fo:build\main.obj /Fd:build\compiler.pdb /Fe:build\types.exe
.\build\types.exe
```

macOS에서는 Clang을 사용할 수 있는지 확인한 뒤 이 폴더의 터미널에서 실행해.

```sh
mkdir -p build
clang++ -std=c++17 -Wall -Wextra -g -O0 main.cpp -o build/types
./build/types
```

빌드에 실패하면 실행을 멈추고 오류를 확인해. 실행 파일은 각 운영체제에서 따로 만들어야 해.

## 이해 확인과 직접 실습

1. 실행 전에 두 출력이 다른 이유를 네 말로 설명해봐.
2. `return 0;` 앞에 아래 코드를 추가해. 먼저 출력값을 예상하고, 저장·재빌드·실행해서 비교해.

```cpp
double result = total / count;
std::cout << "result: " << result << '\n';
```

힌트: 오른쪽의 나눗셈이 어떤 타입으로 수행되는지부터 생각해봐.

3. `total`과 `count`의 타입을 유지하면서, `result`에 소수 부분을 포함한 몫을 저장할 방법도 생각해봐. 이건 다음 타입 변환 수업으로 연결할 과제야.

이전 1-1의 재빌드 비교와 디버거 실습은 확인되지 않은 항목으로 남겨두고, 이번 실습도 결과와 설명을 확인한 뒤 완료 기록을 갱신해.

## 참고 문서

- [Dart의 산술 연산자](https://dart.dev/language/operators#arithmetic-operators)
- [C++의 곱셈·나눗셈·나머지 연산자](https://learn.microsoft.com/en-us/cpp/cpp/multiplicative-operators-and-the-modulus-operator?view=msvc-170)
