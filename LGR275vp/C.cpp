#include <iostream>

using namespace std;

int main() {
    int n, x, y;
    int a[1001];
    int count = 0, longest = 0, temp;
    scanf("%d %d %d", &n, &x, &y);
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        if (temp == x + y || x == temp + y || y == x + temp || temp == x * y || x == temp * y || y == x * temp) {
            count++;
            longest = temp > longest ? temp : longest;
        }
    }
    printf("%d %d", count, longest);
}