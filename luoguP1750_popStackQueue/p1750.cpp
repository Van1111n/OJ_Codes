#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int min(vector<int> v) {
    int k = 0;
    for (int i = 0; i < v.size(); i++) {
        k = v.at(i) < v.at(k) ? i : k;
    }
    return k;
}

int main() {
    int n, c;
    scanf("%d %d", &n, &c);
    vector<int> v(c);
    for (int i = 0; i < c; i++) {
        scanf("%d", &v.at(i));
    }
    for (int i = 0; i < n - c; i++) {
        printf("%d ", v.at(min(v)));
        scanf("%d", &v.at(min(v)));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < c; i++) {
        printf("%d ", v.at(i));
    }
}