// 2024.08.08
// 송현준
// 정올 1419 : 엔디안
// struct, union

#include <stdio.h>

struct bits_tag{
	unsigned int a:8; // 32비트 unsigned int 중 8비트를 a로 쪼갠다.
	unsigned int b:8;// 32비트 unsigned int 중 a 다음 8비트를 b로 쪼갠다.
	unsigned int c:8; // 32비트 unsigned int 중 b 다음 8비트를 c로 쪼갠다.
	unsigned int d:8; // 32비트 unsigned int 중 c 다음 8비트를 d로 쪼갠다.
};

union register_tag{
	struct bits_tag Bit8;
	unsigned int Union; // 32비트
};
// Bit는 1바이트씩, Union은 4바이트

int main(){
	union register_tag data;
	union register_tag invert_data;
	scanf("%u", &data.Union);
	
	invert_data.Bit8.a = data.Bit8.d;
	invert_data.Bit8.b = data.Bit8.c;
	invert_data.Bit8.c = data.Bit8.b;
	invert_data.Bit8.d = data.Bit8.a;

	printf("%u",invert_data.Union);
	// 출력할 떄 부호있는 정수로 해석되지 않게 서식지정자를 %u로 설정
	
	return 0;
}