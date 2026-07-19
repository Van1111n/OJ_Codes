#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;

    int worth, paid;
    std::string mode;
    int loss = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> worth >> paid >> mode;
        if (mode == "keep") {
            loss += paid - worth;
        }
    }
    std::cout << loss << std::endl;
    return 0;
}