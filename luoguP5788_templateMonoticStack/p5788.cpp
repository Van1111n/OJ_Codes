#include <iostream>
#include <stack>
#include <vector>
#include <utility>

int main(){
    int n;
    scanf("%d", &n);

    std::vector<std::pair<int, int>> a(n, {0, 0});
    std::vector<int> f(n+1, 0);
    std::stack<std::pair<int, int>> st;
    for (int i = 0; i < n; i++) {
        a[i].first = i+1;
        scanf("%d", &a[i].second);
    }

    for (auto it : a) {
        while (!st.empty() && st.top().second < it.second) {
            f[st.top().first] = it.first;
            st.pop();
        }
        st.push(it);
    }

    for (int i=1; i<=n; i++){
        printf("%d ", f[i]);
    }

    return 0;
}