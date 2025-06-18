cách 1 :
#include <stdio.h>
int Tong(int n){
	int sum = 0;
	for(int i = 1; i <= n; i++){
        sum += i;
	}
}
//độ phức tạp là O(n)

cách 2 :
int Tong(int n){
	return n * (n + 1) / 2;
}
//độ phức tạp là O(1)