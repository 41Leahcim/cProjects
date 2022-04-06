#include <stdio.h>
#include <time.h>

int main(){
	clock_t start = clock();
	for(volatile int i = 0;i < 1000000000;i++);
	printf("%lf\n", (double)(clock() - start) / CLOCKS_PER_SEC);
}
