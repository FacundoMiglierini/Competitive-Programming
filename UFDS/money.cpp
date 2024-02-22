#include <bits/stdc++.h>
using namespace std;

int N, n, m, x, y;

vector<int> friends_debt;
vector<int> parents;


void unionSet(int x, int y){
	int idx_parent;
	if(parents[x] != parents[y]){
		parents[y] = parents[x];
		friends_debt[parents[y]] = friends_debt[parents[y]] + friends_debt[y];	
	}
}

bool isPossible(){

	for(int j = 0; j < n; j++){
		if(parents[j] == j && friends_debt[j] != 0){
			return false;
		}
	}
	return true;

}

int main(){
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> n >> m;
		friends_debt.resize(n);
		parents.resize(n);

		for(int j = 0; j < n; j++){
			cin >> friends_debt[j];
			parents[j] = j;
		}
		for(int k = 0; k < m; k++){
			cin >> x >> y;
			unionSet(x, y);
		}

		if(isPossible())
			cout << "POSSIBLE" << endl;
		else
			cout << "IMPOSSIBLE" << endl;

		friends_debt.clear();
		parents.clear();
	}
}
