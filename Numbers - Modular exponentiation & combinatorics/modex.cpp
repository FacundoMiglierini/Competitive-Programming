#include <bits/stdc++.h>
using namespace std;

int modex(int x, int y, int n){
	int res = 1;
	while(y != 0){
		if (y % 2 == 1)
			res = (res * x) % n;
		x = (x * x) % n;
		y = y / 2;
	}

	return res;
}

int main(){
	int x, y, n, N;
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> x >> y >> n;
		cout << modex(x, y, n) << endl;
	}
	cin >> N;
}
