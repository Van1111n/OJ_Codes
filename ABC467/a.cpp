#include <iostream>

int main() {
    int h, w;
    std::cin >> h >> w;
    std::cout << (400 * w >= h * h ? "Yes" : "No") << std::endl;
    return 0;
}