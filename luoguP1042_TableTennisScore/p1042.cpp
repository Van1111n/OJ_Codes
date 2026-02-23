#include <cstdio>
#include <cmath>
#define N 65536
int main(){
    char results[N];
    char c;
    int myScore=0, opponentScore=0;
    int i=0;
    while((c=getchar())!='E'){
        results[i++]=c;
    }
    for (int i=0; results[i]!='\0'; i++){
        if (results[i]=='W') myScore++;
        if (results[i]=='L') opponentScore++;
        if ((myScore>=11 || opponentScore>=11) && abs(myScore-opponentScore)>=2){
            printf("%d:%d\n", myScore, opponentScore);
            myScore=0; opponentScore=0;
        }
    }
    printf("%d:%d\n\n", myScore, opponentScore);
    myScore = 0;
    opponentScore = 0;
    for (int i=0; results[i]!='\0'; i++){
        if (results[i]=='W') myScore++;
        if (results[i]=='L') opponentScore++;
        if ((myScore>=21 || opponentScore>=21) && abs(myScore-opponentScore)>=2){
            printf("%d:%d\n", myScore, opponentScore);
            myScore=0; opponentScore=0;
        }
    }
    printf("%d:%d\n", myScore, opponentScore);
    myScore = 0;
    opponentScore = 0;
    return 0;
}