#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cin >> N >> K;
        a.resize(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }

        long long res = 0;
        int min = 0;
        int g;
        for (int start = 0; start + K <= N; start++) {
            min = start;
            for (int j = start; j < start + K; j++) {
                if (a[j] < a[min]) {
                    min = j;
                }
            }
            res += a[min];
            g = a[min];
            for (int j = min; j < start + K; j++) {
                a[j] -= g;
            }
            start = min;
        }

        cout << res << std::endl;
    }
}
