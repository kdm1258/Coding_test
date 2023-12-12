#include <stdio.h>
	int arr[2001][2001] = {0};
	int c[2001] = {0};
	int n = 0;
int sol(int v);
int main() {
	int asso = 0;
	int m = 0 ;
	int tmp1 = 0, tmp2 = 0;

	//배열 초기화
	scanf("%d %d", &n, &m);

	for (int i = 1 ; i <= m ; i++){
		scanf("%d %d", &tmp1, &tmp2);
		arr[tmp1][tmp2] = 1;
	}
	//연합 확인
	for (int v = 1 ; v <= n ; v++){
		if (c[v] !=1) asso += sol(v);
	}
		printf("%d\n", asso);
		return 0;
		
}
int sol(int v){
	c[v] = 1;
	for (int i = 1; i<=n ; i++){
		if ((arr[v][i] == 1)&&(arr[i][v] == 1)&&(c[i] != 1)){
			sol(i);
		}
	}
	return 1;
}
