#include <bits/stdc++.h>

using namespace std;

int main(){
    int bpm;
    scanf("%d",&bpm);
    int time = 60000/bpm;
    printf("%d %d %d %d %d", time, time, time/2, time/2, time);
    return 0;
}