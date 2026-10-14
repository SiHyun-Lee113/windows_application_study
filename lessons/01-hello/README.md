# 1-1. 첫 C++ 프로그램: 빌드와 실행

이 예제는 Windows와 macOS에서 사용할 수 있는 표준 C++ 코드야. 이번 실습에서는 소스 코드를 빌드해 실행 파일을 만드는 흐름을 확인해보자.

## Windows에서 실습하기

시작 메뉴에서 **Developer PowerShell for VS 2022**를 열어. 이 셸은 C++ 컴파일러와 라이브러리를 찾을 수 있도록 환경 변수를 설정해줘.

아래 명령은 Developer PowerShell에서 순서대로 실행해.

```powershell
Set-Location 'C:\Users\tlgus\StudioProjects\study\lessons\01-hello'
New-Item -ItemType Directory -Path build -Force | Out-Null
Set-Location build
cl /nologo /EHsc /std:c++17 /W4 /Zi /Od ..\main.cpp /Fe:hello.exe
.\hello.exe
```

`cl` 명령은 컴파일과 링크를 수행해. 생성된 `hello.exe`를 실행하면 다음 결과가 나와.

```text
Hello, C++!
Lesson: 1
```

- `/std:c++17`: 이 예제에서 사용할 C++ 표준 버전이야.
- `/EHsc`: C++ 예외 처리 모델을 설정해.
- `/W4`: 경고 수준을 설정해.
- `/Zi`, `/Od`: 디버깅 정보를 만들고 최적화를 꺼서 다음 디버거 실습을 준비해.
- `/Fe:hello.exe`: 실행 파일 이름을 지정해.

빌드가 실패하면 실행 단계로 넘어가지 말고 오류 메시지를 확인해. 이전에 만들어진 실행 파일이 남아 있을 수 있어.

## Visual Studio 2022에서 빌드·실행·디버깅하기

같은 `main.cpp`를 사용하는 [hello.vcxproj](hello.vcxproj)를 준비했어. 프로젝트 파일은 어떤 소스를 어떤 설정으로 빌드할지 Visual Studio에 알려줘. 이 프로젝트는 Windows용이며, C++17·Debug·x64 설정을 사용해.

1. Visual Studio 2022에서 **파일 → 열기 → 프로젝트/솔루션**을 선택하고 이 폴더의 `hello.vcxproj`를 열어.
2. 상단 구성이 **Debug**, 플랫폼이 **x64**인지 확인해. 솔루션 탐색기에서 `main.cpp`를 열어.
3. **Ctrl+Shift+B**로 빌드하고, **Ctrl+F5**로 디버거 없이 실행해.
4. 첫 번째 `std::cout` 줄에 커서를 놓고 **F9**로 중단점을 설정해.
5. **F5**로 디버깅을 시작하면 그 줄을 실행하기 전에 멈춰. 그때 앞의 `int lesson = 1;`은 이미 실행된 상태야.
6. `lesson`에 마우스를 올리거나 지역 변수(Locals) 창에서 값을 확인해. **F10**으로 다음 문장을 실행하고 **F5**로 계속 실행해.

빌드 결과는 `build/vs/x64/Debug/hello.exe`에 생성돼. 터미널 실습의 `build/hello.exe`와 경로가 달라. 어느 방식을 사용하든 소스를 수정한 뒤에는 해당 방식으로 다시 빌드해.

## VS Code에서 작성하고 빌드하기

VS Code로 이 폴더를 열어 `main.cpp`를 편집하고, 앞서 사용한 Developer PowerShell에서 동일한 `cl` 명령으로 빌드해도 돼.

VS Code 안에서 빌드·디버깅 버튼을 사용하려면 C/C++ 확장과 컴파일러·디버거 연결 설정이 필요해. 확장 자체에는 C++ 컴파일러가 포함되어 있지 않아. Windows에서는 이미 설치된 MSVC를 활용할 수 있어.

VS Code의 일반 PowerShell 터미널에는 개발용 환경이 설정되어 있지 않을 수 있어. 이번 실습은 먼저 별도의 Developer PowerShell에서 빌드해. 편집기 선택과 컴파일러 선택은 별개의 문제야.

## macOS에서 실습하기

자택 Mac의 도구 설치 상태는 아직 확인하지 않았어. `clang++ --version`으로 C++ 컴파일러를 사용할 수 있는지 먼저 확인해.

프로젝트를 Mac으로 옮긴 뒤, 이 예제 폴더의 터미널에서 실행해.

```sh
mkdir -p build
clang++ -std=c++17 -Wall -Wextra -g -O0 main.cpp -o build/hello
./build/hello
```

Mac에서 생성한 실행 파일은 Mac용이야. 소스 코드를 공유하되 각 운영체제에서 다시 빌드해.

## 직접 해볼 과제

1. 먼저 현재 예제를 직접 빌드하고 실행해.
2. `main.cpp`에서 `lesson`의 초깃값을 `1`에서 `2`로 바꾸고 저장해.
3. 다시 빌드하기 전에 기존 실행 파일을 실행하고 결과를 관찰해.
4. 다시 빌드한 뒤 실행하고 이전 결과와 비교해.
5. 소스를 저장하는 것과 실행 파일을 다시 만드는 것이 어떻게 다른지 네 말로 설명해봐.

다음 실습에서는 중단점을 걸고 `lesson`의 값을 디버거로 확인할 거야. 이 회차는 직접 실습과 이해 확인, 디버거 실습을 마친 뒤 완료 처리해.

## 참고 문서

- [MSVC로 명령줄에서 C++ 프로그램 빌드하기](https://learn.microsoft.com/en-us/cpp/build/walkthrough-compiling-a-native-cpp-program-on-the-command-line?view=msvc-170)
- [Visual Studio에서 콘솔 앱 빌드·실행하기](https://learn.microsoft.com/en-us/cpp/build/vscpp-step-2-build?view=msvc-170)
- [Visual Studio의 C++ 디버거 시작하기](https://learn.microsoft.com/en-us/visualstudio/debugger/quickstart-debug-with-cplusplus?view=visualstudio)
- [VS Code의 C/C++ 지원과 컴파일러 설정](https://code.visualstudio.com/docs/languages/cpp)
