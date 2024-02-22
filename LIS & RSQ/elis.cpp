#include <bits/stdc++.h>
using namespace std;

vector<int> results;

int elis(vector<int> &seq, int idx){
	
	if (results[idx] != -1) return results[idx];
	
	results[idx] = 1;

	for(int i = 0; i <= idx; i++){
		if((elis(seq, i) + 1 > results[idx]) && (seq[i] < seq[idx])){
			results[idx] = elis(seq, i) + 1; 
		}
	}
	
	return results[idx];
}


int main(){
	vector<int> seq;
	int N, number;
	cin >> N;
	seq.resize(N, 0);
	results.resize(N, -1);

	for(int i = 0; i < N; i++){
		cin >> number;
		seq[i] = number;
	}

	elis(seq, N - 1);

	cout << *max_element(results.begin(), results.end()) << endl;
	return 0;
}
