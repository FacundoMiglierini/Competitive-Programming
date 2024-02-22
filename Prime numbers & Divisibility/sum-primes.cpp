#include <bits/stdc++.h>
using namespace std;

vector<int> primes;
vector<int> elems;

void sieve(int n){
	vector<bool> sieve;
	sieve.resize(n, true);
	sieve[0] = false;
	primes.append(2);
	int i = 4;
	while(i <= n){
		sieve[i] = false;
		i = i + 2;
	}

	i = 3;
	while (i < n){
		if (sieve[i]){
			primes.push_back(i);
			int j = i + 1;
			while(j < n){
				sieve[j] = false;
				j = j + 1;
			}
		i = i + 2;
	}
}

int main(){
	int N;

	while(cin){
		cin >> N;
		primes.clear();
		elems.clear();
		sieve(sqrt(N));
		calculate_sum();
		if(elems.size() != 4)
			cout << "Impossible" << endl;
		else{
			for(int i = 0; i < 4; i++)
				cout << elems[i];
			cout << endl;	
		}
	}	
}
