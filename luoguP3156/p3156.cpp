#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> students;
    students.resize(n);
    for (int i = 0; i < n; i++) {
        std::cin >> students[i];
    }

    int ask;
    for (int i=0; i<m; i++) {
        std::cin >> ask;
        std::cout << students[--ask] << std::endl;
    }

    return 0;
}