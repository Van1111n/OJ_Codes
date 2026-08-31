#include <iostream>

struct Cabinet {
    int a, b, c;
};

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;

        int win = 0;
        while (n--) {
            int a, b, c;
            std::cin >> a >> b >> c;
            if (c == 0) {
                win++;
            } else if (c == 1) {
                if (a > 0) {
                    win++;
                }
            } else {
                win++;
            }
        }
        std::cout << (win % 2 ? "First" : "Second") << '\n';
    }
}