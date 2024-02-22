#include <bits/stdc++.h>
using namespace std;

vector<int> results;

int lis(vector<int> &buildings, int idx){
	
	if(results[idx] != -1)
		return results[idx];

	results[idx] = 1000000001;
	int pot = pow(2, (int) log2(idx));
	int i;
	while (pot != 0){
		i = idx - pot;
		if((lis(buildings, i) + abs(buildings[idx] - buildings[i]) < results[idx])){
			results[idx] = lis(buildings, i) + abs(buildings[idx] - buildings[i]);
		}
		pot = pot / 2;
	}
	return results[idx];
}

int main(){
	vector<int> buildings;
	int N;

	cin >> N;
	buildings.resize(N + 1);
	results.resize(N + 1, -1);

	for(int i=1; i <= N; i++){
		cin >> buildings[i];
	}

	results[0] = 0;
	buildings[0] = buildings[1];

	cout << lis(buildings, N) << endl;
	return 0;
}
