// 2024.07.25
// 송현준

#include <stdio.h>

int main() {
	float num;
	scanf("%f", &num);
    switch(((int)num)){ // switch 문과 case에는 integer를 사용한다.
		case 4:
			printf("scholarship");
			break;
		case 3:
			printf("next semester");
			break;
		case 2:
			printf("seasonal semester");
			break;
		default :
			printf("retake");
			break;
	}

	return 0;
}
