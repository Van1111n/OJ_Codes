#include <iostream>
#include <random>
#include <cstdlib>
#include <cstdio>
#include <ctime>

int main(){
	srand(time(NULL));
	int r = rand() % 1000 + 1;
	printf("%d\n", r);
	for (int i = 0; i < r; i++){
		for (int j = 0; j <= i; j++){
			int a = rand() % 100 + 1;
			printf("%d ", a);
		} printf("\n");
	}
	return 0;
}