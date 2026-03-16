#include <iostream>
#include <vector>
#include <algorithm>


struct Gold{
    float weight;
    float totalValue;
    float unitValue;

    bool operator<(const Gold& g) {
        return unitValue > g.unitValue;
    }

    void calc_unit_value(){
        unitValue = totalValue / weight;
    }
};

int main(){
    int n;
    float maxWeight;
    scanf("%d %f", &n, &maxWeight);
    std::vector<Gold> golds;
    for (int i=0; i<n; i++){
        Gold temp;
        scanf("%f %f", &temp.weight, &temp.totalValue);
        temp.calc_unit_value();
        golds.push_back(temp);
    }
    std::sort(golds.begin(), golds.end());

    float ans = 0;
    float remainSpace = maxWeight;
    int k = 0;
    while (remainSpace > 0 && k < n) {
        if (golds.at(k).weight < remainSpace){
            ans += golds.at(k).totalValue;
            remainSpace -= golds.at(k++).weight;
            continue;
        } else {
            ans += remainSpace * golds.at(k).unitValue;
            break;
        }
    }
    printf("%.2f", ans);
    return 0;
}