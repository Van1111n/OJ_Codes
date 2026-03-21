#include <iostream>

using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int p[100], t[100];
    for (int i = 0; i < m; i++) {
        scanf("%d", &p[i]);
        --p[i];
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &t[i]);
    }
    for (int i = 0; i < m; i++) {
        int startDay = 1;
        int cur = i;
        while(p[cur]!=-1){
        	//printf("cur:%d pcur:%d\n",cur,p[cur]);
        	cur=p[cur];
        	startDay+=t[cur];
		}
		printf("%d ", startDay);
    }
    // TODO: last date
}