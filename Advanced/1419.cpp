// 2024.08.08
// 송현준
// 정올 1419 : 엔디안
// 비트 연산

#include <iostream>
using namespace std;

int main() {
	unsigned int data;
	// 8 8 8 8
	// 2^8 2^8 2^8 2^8
	cin >> data;
	unsigned int invert_byte[4]; // data byte 역순 저장할 배열
	unsigned int transfom_res=0; // 0인 비트 32개
	
	for (int i = 0; i<4; i++){
		invert_byte[i] = (data >> (8*i)) & ((1<<8)-1);
		// 8 8 8 8
		// 0 8 8 8 식으로 비트를 >>.
		// 맨 밑 단 8비트(256)의 정보만 배열에 저장.
		// 결과적으로 역순으로 저장됨.
		transfom_res |= invert_byte[i] << (8*(3-i));
		// 저장된 바이트들 8 8 8 8 형태가 되도록 위치에 맞게 <<
		// 그 후 |= 연산으로 res의 비트 변경
	}

	cout << transfom_res;
	return 0;
}