#include <iostream>

int main() {
    int n, m;
    int a[1005];

    // a[] is 1-based
    std::cin >> n >> m;
    for (int i=1; i<=n; i++) {
        std::cin >> a[i];
    }

    // 只在前l道菜中挑选并花光k元的方案数plan[l][k]满足:
    // plan[l+1][k] = plan[l][k-a[l]] + plan[l][k]
    // 多一道菜之后，有吃和不吃两种选项，对应RHS的两项.
    // 当然如果k<a[l]，即多的这道菜的价格超过可用资金k，就没有吃的选项了.
    int **plan = new int*[105];
    for (int i=0; i<105; i++) {
        plan[i] = new int[10005]{0};
    }
    plan[1][0] = 1;
    plan[1][a[1]] = 1;
    for (int l=2; l<=n; l++) {
        for (int k=0; k<=m; k++) {
            plan[l][k] = (k>=a[l] ? plan[l-1][k-a[l]] : 0) + plan[l-1][k];
        }
    }
    int ans = plan[n][m];
    std::cout << ans << std::endl;
    return 0;
}