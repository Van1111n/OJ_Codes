#include <iostream>
#define P 1000000007

using namespace std;

int main(){
	int n, w;
	scanf("%d %d",&n,&w);
	int a[1000] = {0};
	for (int i = 0; i < n; i++){
		scanf("%d",&a[i]);
	}
	int p[10001] = {0};
	p[0] = 1;
	for (int i = 1; i <= w; i++){
		int plan = 0;
		for (int j = 0; j < n; j++){
			if (i - a[j] >= 0){
				plan += p[i - a[j]];
				plan %= P;
			}
		}
		p[i] = plan;
	}
	printf("%d\n", p[w]);
	return 0;
}