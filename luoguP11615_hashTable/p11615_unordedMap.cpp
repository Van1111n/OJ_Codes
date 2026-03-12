#include <iostream>
#include <unordered_map>
#define LLU unsigned long long

int main(){
    std::unordered_map<LLU, LLU> map;
    int n;
    LLU x, y;
    LLU ans=0;
    LLU random=0xC95F76553B8C6DF0;
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        scanf("%llu %llu", &x, &y);
        x^=random;
        std::unordered_map<LLU, LLU>::iterator it = map.find(x);
        if (it != map.end()) {
            ans+=(i+1)*it->second;
            it->second=y;
        } else {
            map.insert({x, y});
        }
    }
    printf("%llu\n", ans);
}
