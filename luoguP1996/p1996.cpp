#include <iostream>
#include <vector>
#include <list>

int main() {
    int n, m;
    std::cin >> n >> m;
    m--;

    std::vector<int> man(n);
    for (int i = 0; i < n; i++) {
        man[i] = i + 1;
    }

    int crt = 0;
    while (!man.empty()) {
        crt = (crt + m) % man.size();
        std::cout << man[crt] << ' ';
        man.erase(man.begin()+crt);
    }

    return 0;
}