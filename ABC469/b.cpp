#include <iostream>
#include <string>

int main() {
    int n;
    std::string s;
    std::cin >> n >> s;
    s = 'x' + s + 'x';
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i-1]=='x' && s[i] == 'x' && s[i+1] == 'x') {
            ++count;
        }
    }
    std::cout << count << std::endl;
    return 0;
}