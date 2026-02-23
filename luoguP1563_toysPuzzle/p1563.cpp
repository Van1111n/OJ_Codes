#include <cstdio>
#include <cstdlib>

using namespace std;

struct Man{
    bool orientation;
    char job[11];
};

struct Step{
    bool direction;
    int stepSize;
};

int main(){
    int manNum, stepNum;
    int current=0;
    scanf("%d %d", &manNum, &stepNum);
    Man* mans=(Man *)malloc(sizeof(Man)*manNum);
    Step* steps=(Step *)malloc(sizeof(Step)*stepNum);
    for (int i = 0; i < manNum; i++){
        scanf("%d %s", &mans[i].orientation, &mans[i].job);
    }
    for (int i=0; i<stepNum; i++){
        scanf("%d %d",&steps[i].direction, &steps[i].stepSize);
    }
    for (int i=0; i<stepNum; i++){
        if (mans[current].orientation ^ steps[i].direction) current+=steps[i].stepSize;
        else current-=steps[i].stepSize;
        while(current<0) current+=manNum;
        if (current>=manNum) current%=manNum;
    }
    printf("%s", mans[current].job);
}