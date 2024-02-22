#include <bits/stdc++.h>
using namespace std;

int main(){
	long n, count;
	cin >> n;
	while(n != 0){
		count = sqrt(n);
		if(count * count == n)
			cout << "yes" << endl;
		else
			cout << "no" << endl;

		cin >> n;
	}
}
