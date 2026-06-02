#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
// fix:修复溢出问题
#define LLD long long int

using namespace std;

int main() {
    LLD n, w;
    scanf("%lld %lld", &n, &w);
    vector<LLD> a(n);
    for (LLD i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    // 对价格排序，因为先买越买到后面优惠券越多，所以应该把贵的东西放到后面以免优惠券浪费
    sort(a.begin(), a.end());
    // 如果开始不额外买优惠券，买第i个商品的时候有i个优惠券(0-base)，所以等效价格可以减去i
    for (LLD i = 0; i < n; i++) {
        // fix:修复了a[i]可能小于0的问题
        a[i] = max(a[i] - i, 0LL);
    }
    // 初始时每多买一张优惠券就可以使所以商品等效价格减1，但不低于0，所以需要比较优惠券价格w和商品价格大于0的数量c，决定是否购买优惠券
    // 更进一步，对等效以后的价格排序，查看第n-w个元素的值就知道要买几张优惠券了
    sort(a.begin(), a.end());
    // fix: 修复了n-w可能指针越界的问题
    LLD vouchar;
    if (n - w < 0) {
        vouchar = 0;
    } else {
        vouchar = a[max(n - w, 0LL)];
    }
    LLD sum = 0;
    for (LLD i = max(n - w, 0LL); i < n; i++) {
        sum += a[i];
    }
    // 本来应该是 sum - w * vouchar + w * vouchar
    // 减去优惠券节省的花费（w恰为后面商品的个数）再加上购买优惠券的花费
    // 从这里可以看出，实际上是优惠券节省的花费==购买优惠券的花费的时候是最优决策
    LLD ans = sum;
    cout << ans << endl;
    return 0;
}