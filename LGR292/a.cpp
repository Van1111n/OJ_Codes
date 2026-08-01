#include <iostream>
#include <string>

int main() {
    std::string s;
    s.reserve(500);
    std::cin >> s;

    int n = s.length();
    for (int i = 0; i < n; i++) {
        int echoLen = n - i;
        if (i % 2 == 0) {
            // r2l
            for (int j=0; j<echoLen; j++) {
                putchar(s[j]);
            }
        } else {
            // l2r
            for (int j=n-1; j>n-1-echoLen; j--) {
                putchar(s[j]);
            }
        }
    }
    return 0;
}