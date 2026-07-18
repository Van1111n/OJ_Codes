#include <iostream>
#include <string>
#include <cmath>

// 0-based
void move(std::string &s, int src, int dest) {
    if (abs(dest - src) <= 2 || s[dest] != '-' || s[dest + 1] != '-' || s[src] == '-' || s[src] == '-') {
        throw "Invalid move\n";
    }
    s[dest] = s[src];
    s[dest+1] = s[src+1];
    s[src] = s[src + 1] = '-';
    return;
}

int main() {
    int n;
    std::cin >> n;

    std::string s;
    s.resize(2*n+2);
    for (int i=0; i<n; i++) {
        s[i] = 'o';
    }
    for (int i=n; i<2*n; i++) {
        s[i] = '*';
    }
    s[2*n] = s[2*n+1] = '-';
    std::cout << s << std::endl;

    for (int i=0; i<n-4; i++) {
        move(s, n-1-i, 2*n-2*i);
        std::cout << s <<std::endl;
        move(s, 2*n-2*i-2, n-1-i);
        std::cout << s << std::endl;
    }
    move(s, 3, 8);
    std::cout << s << std::endl;
    move(s, 7, 3);
    std::cout << s << std::endl;
    move(s, 1, 7);
    std::cout << s << std::endl;
    move(s, 6, 1);
    std::cout << s << std::endl;
    move(s, 0, 6);
    std::cout << s << std::endl;
}