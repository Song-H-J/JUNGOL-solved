#include <stdio.h>
#include <string.h>

void decToB(int,int);
void decTo2(int);
void decTo8(int);
void decTo16(int);

int main() {
	int N,B;
	scanf("%d%d",&N,&B);
	decToB(N, B);
	return 0;
}

void decToB(int N, int B){
	switch(B){
		case 2:
			decTo2(N);
			break;
		case 8:
			decTo8(N);
			break;
		case 16:
			decTo16(N);
			break;
	}
	return;
}

void decTo2(int N){
	int bin[17];
	memset(bin, 0, sizeof(bin));
	int cnt = 0;
	
	while(N){
		bin[cnt] = N % 2;
		N = N/2;
		cnt++;
	}
	
	for(int i = cnt -1 ; i>=0; i--){
		printf("%d",bin[i]);
	}
}

void decTo8(int N){
	int eit[20];
	memset(eit,0,sizeof(eit));
	int cnt = 0;

	while(N){
		eit[cnt] = N % 8;
		N/=8;
		cnt++;
	}

	for(int i = cnt -1 ; i>=0; i--){
		printf("%d",eit[i]);
	}
}

void decTo16(int N){
	char hex[20];
	memset(hex,0,sizeof(hex));
	int cnt = 0;
	int tmp;

	while(N){
		tmp = N%16;
		if(tmp>9){
			tmp = 'A' + (tmp - 10);
		} else{
			tmp = '0' + tmp;
		}
		hex[cnt] = tmp;
		N/=16;
		cnt++;
	}

	for(int i = cnt -1 ; i>=0; i--){
		printf("%c",hex[i]);
	}
}