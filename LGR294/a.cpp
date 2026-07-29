#include <iostream>

int main() {
    int n, t;
    int p[100005];
    std::cin >> n >> t;
    int star = 0;
    for (int i=0; i<n; i++) {
        std::cin >> p[i];
        if (p[i]==t) {
            star += 2;
        } else if (abs(p[i]-t)<=2){
            star += 1;
        } else {

        }
    }
    std::cout << star << std::endl;
}