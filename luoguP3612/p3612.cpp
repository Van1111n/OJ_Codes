#include <iostream>
#include <string>

using LLU = unsigned long long;

int main() {
    std::string s;
    LLU n;
    std::cin >> s >> n;

    LLU originalLength = s.length();
    LLU curLength = originalLength;
    while (curLength < n) {
        curLength *= 2;
    }

    while (n > originalLength) {
        if (n == curLength / 2 + 1) {
            --n;
        } else {
            n -= curLength / 2 + 1;
        }
        while (curLength > n) {
            curLength /= 2;
        }
        curLength *= 2;
    }

    // 1-0-base转换
    char res = s.at(--n);
    std::cout << res;
}