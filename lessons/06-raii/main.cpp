#include <fstream>
#include <iostream>

int writeNote()
{
    std::ofstream file{"note.txt"};
    if (!file)
    {
        std::cerr << "Could not open note.txt\n";
        return 1;
    }

    file << "Learning RAII\n";
    return 0;
}

int main()
{
    const int result{writeNote()};
    std::cout << "result: " << result << '\n';
    return result;
}
