#include <stdio.h>

int main() {
	char stack[50];
	char top = 't';
	int height = 0;

	scanf("%s", stack);
	for(int i = 0; i<50; i++){
		if(stack[i]==0)
			break;
		else if(stack[i]==top){
			height+=5;
		} else{
			height+=10;
		}
		top = stack[i];
	}
	printf("%d", height);
	return 0;
}