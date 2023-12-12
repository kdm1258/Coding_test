#include <iostream>
using namespace std;
	int arr[1002][1002] = {0};
	int cnt[1002][1002] = {0};
	int n = 0;
	int k = 0;

int cntCld(int arr[1002][1002], int cnt[1002][1002]);
int main() {
	cin >> n >> k;
	int cld = 0;
	
	for (int i = 1 ; i <=n ; i++){
		for (int j = 1 ; j <= n ; j++){
			cin >> arr[i][j];
		}
	}
	cntCld(arr,cnt);
	for (int i = 1 ; i <=n ; i++){
		for (int j = 1 ; j <= n ; j++){
			if (arr[i][j] ==1) cnt[i][j] = -1;
		}
	}
	
	for (int i = 1 ; i <=n ; i++){
		for (int j = 1 ; j <= n ; j++){
			if(cnt[i][j] == k)
			cld++;
		}
	}
	printf("%d\n", cld);
	
}
int cntCld(int arr[1002][1002],int cnt[1002][1002]){
	for (int i = 1 ; i <= n ; i++){
		for (int j = 1 ;j <= n ; j++){
			if ((arr[i][j] == 1)&&(cnt[i][j] != -1)){	
				cnt[i-1][j-1]++;
				cnt[i-1][j]++;
				cnt[i-1][j+1]++;
			 	cnt[i][j-1]++;
				cnt[i][j+1]++;
			 	cnt[i+1][j-1]++;
				cnt[i+1][j]++;
			 	cnt[i+1][j+1]++;
			}
		}
	}
	return 0; 
}
