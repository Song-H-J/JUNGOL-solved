// 2024. 07. 29
// 송현준

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool is_prime_number(int);
void calc_nearest_prime_number(int);

int main() {
	int N;
	int num[100];
	int i, tmp;
	scanf("%d\n", &N);
	for(i=0; i<N; i++){
		scanf("%d\n", &tmp);
		num[i] = tmp;
	}

	for(i=0; i<N; i++){
	 	calc_nearest_prime_number(num[i]);
	}

	return 0;
}

void calc_nearest_prime_number(int n){
	int post_prime = 0;
	int pre_prime = 0;
	int post_gap, pre_gap;
	int inc = 1;

	while(1){
		if(is_prime_number(n)){
			printf("%d\n", n);
			return;
		}

		if((post_prime ==0) && is_prime_number(n+inc)){
			post_prime = n+inc;
		}

		if((pre_prime == 0) && is_prime_number(n-inc)){
			pre_prime = n-inc;
		}

		if(pre_prime!=0 && post_prime!=0){
			break;
		}
		inc ++;
	}
	post_gap = abs(n-post_prime);
	pre_gap = abs(n-pre_prime);

	if(post_gap>pre_gap) printf("%d\n", pre_prime);
	else if(post_gap<pre_gap) printf("%d\n", post_prime);
	else if(post_gap==pre_gap) printf("%d %d\n", pre_prime, post_prime);
	return;
}

bool is_prime_number(int n){
	if(n==1) {return false;}
	if((n==2)||(n==3)||(n==5)||(n==7)) return true;
	if(((n%2==0)||(n%3==0))) return false;

	for(int j = 5; ((j<n)&&(j+2<n)); j+=6){
		if(((n%j)==0)||((n%(j+2))==0)) return false;
	}
	return true;
}