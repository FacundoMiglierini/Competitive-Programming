#include <bits/stdc++.h>
using namespace std;

int N, n, m, x, y;


int pathCompression(vector<int> &parents, int idx_parent){
	
	if(idx_parent != parents[idx_parent])
		parents[idx_parent] = pathCompression(parents, parents[idx_parent]);

	return parents[idx_parent];
}

void unionSet(vector<int> &friends_debt, vector<int> &parents, vector<int> &ranks, int x, int y){
	int idx_parent;
	if(ranks[x] > ranks[y]){
		parents[y] = x;
		idx_parent = pathCompression(parents, y);
		friends_debt[idx_parent] = friends_debt[idx_parent] + friends_debt[y];	
	}else{
		if(ranks[x] == ranks[y])
			ranks[y]++;
		parents[x] = y;
		idx_parent = pathCompression(parents, x);
		friends_debt[idx_parent] = friends_debt[idx_parent] + friends_debt[x];	
	}
}

bool isPossible(vector<int> &friends_debt, vector<int> &parents){

	for(int j = 0; j < n; j++){
		if(parents[j] == j && friends_debt[j] != 0){
			return false;
		}
	}
	return true;

}

int main(){
	vector<int> friends_debt;
	vector<int> parents;
	vector<int> ranks;
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> n >> m;
		friends_debt.resize(n);
		parents.resize(n);
		ranks.resize(n);

		for(int j = 0; j < n; j++){
			cin >> friends_debt[j];
			parents[j] = j;
			ranks[j] = 0;
		}
		for(int k = 0; k < m; k++){
			cin >> x >> y;
			unionSet(friends_debt, parents, ranks, x, y);
		}

		if(isPossible(friends_debt, parents))
			cout << "POSSIBLE" << endl;
		else
			cout << "IMPOSSIBLE" << endl;

		friends_debt.clear();
		parents.clear();
		ranks.clear();
	}
}
