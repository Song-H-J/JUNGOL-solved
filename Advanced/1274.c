// 2024. 07. 25.
// 송현준

#include <stdio.h>
#include <string.h>

int main() {
	int bin[8];
	int deci = 0;
	int isMinus = 1;
	memset(bin, 0, sizeof(bin));

	for(int i = 0; i<8; i++){
		scanf("%1d", &bin[i]);
	}
	if(bin[0]){ // 음수인 경우
		int cnt = 8;
		while(cnt--){
			if(bin[cnt]){ // -1 비트 빼기
				// 1인 비트를 만날 때까지
				// 그 아래의 0인 비트를 모두 1로
				// 1인 비트는 0으로
				bin[cnt]=0;
				break;
			} else {
				bin[cnt]=1;
			}
		}
		for(int i = 0; i<8; i++){ // 비트 반전
			bin[i] = (bin[i])?0:1;
		}
		isMinus = -1;
	}

	for(int i = 0; i<8; i++){
		deci = deci * 2 + bin[i]; 
	}
	deci*=isMinus; // 양수면 isMinus가 1, 음수는 isMinus가 -1
	printf("%d", deci);

	return 0;
}