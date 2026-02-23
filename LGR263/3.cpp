#include <stdio.h>
#include <stdlib.h>

class room
{
    public:
    long long col;
    long long row;
    long long seat(){
        return col*row;
    }
};


int main(){
    long long n, m;
    long long roomUsed=0;
    room *rooms;
    scanf("%lld %lld", &n, &m);
    rooms=(room*)malloc(sizeof(room)*n);
    for (long long i=0; i<n; i++){
        scanf("%lld %lld", &rooms[i].row, &rooms[i].col);
    }
    long long k=0;
    while (m>0){
        roomUsed++;
        m-=rooms[k].seat();
        k++;
    }
    printf("%lld", roomUsed*2);
}