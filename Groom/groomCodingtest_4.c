#include <stdio.h>
#include <stdlib.h>

int many2[500001][2] = {0};
int cntSame[500001] = {0};

int bin(int num, int i);
int Desc(const void *a, const void *b){return *(int*)b - *(int*)a; }

int main() {
	int n = 0;
	int k = 0;

	scanf("%d %d",&n , &k );
	for (int i = 1 ; i <= n ; i++){
        scanf("%d",&many2[i][1]);
	}
	for (int i = 1; i <= n ; i++){ //1의 개수가 많은 순으로 내림차순 정 
		cntSame[bin(many2[i][1],i)]++;
	}
    qsort(many2+1, n, sizeof(*many2), Desc);

    // for (int i = 1; i <= n ; i++){
    //     printf("%d ", cntSame[i]);
    // }

	for (int i = 1 ; i <= n ; ){ //1의 개수가 같은 숫자는 10진수를 기준으로 내림차순 정렬
        qsort(&(many2[i][1]),cntSame[many2[i][0]], sizeof(*many2), Desc);
        i += cntSame[many2[i][0]];
	}

    // for (int i = 1; i <= n ; i++){
    //     printf("\n%d %d \n", many2[i][1], many2[i][0]);
    // }

    printf("%d", many2[k][1]);
}
int bin(int num,int i){
	if(num > 1) bin(num/2, i);
	if ((num%2)==1) many2[i][0]++;
	return many2[i][0];
}
