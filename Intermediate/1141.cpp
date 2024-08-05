// 2024.08.06
// 송현준
// stack

#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<int> watchingCow;
	int n;
	long long cnt = 0;

	cin >> n;
	int* cow = new int[n];

	for(int i = 0; i<n; i++)
		cin >> *(cow+i);

	for(int i = 0; i<n; i++){
		while(!watchingCow.empty() && *(cow+i)>=watchingCow.top())
			watchingCow.pop();
		cnt+=watchingCow.size();
		watchingCow.push(*(cow+i));
	}
	
	cout << cnt;

	delete [] cow;
	return 0;
}