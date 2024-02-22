#include <bits/stdc++.h> 
using namespace std;

vector<string> routines;
vector<vector<int>> memo;
vector<bool> visited;
int res = INT_MAX;
int R;

int coincidences(string a, string b){
	int counter = 0;
	int posA = 0, posB = 0;
	while(posA < a.size() and posB < b.size()){
		if(a[posA] < b[posB])
			posA++;
		else
			if(a[posA] > b[posB])
				posB++;
			else{
				posA++;
				posB++;
				counter++;
			}
	}
	return counter;
}


void memorization(){
	for(int i = 0; i < R; i++){
		for(int j = 0; j < i; j++)
			memo[i][j] = memo[j][i] = coincidences(routines[i], routines[j]);
	}
}

void DR(int cant, int sum, int selected){
	if (cant == R - 1){
		if (sum < res)
			res = sum;
	}
	else{
		visited[selected] = true;
		for(int i = 0; i < routines.size(); i++){
			if(!visited[i])
				DR(cant + 1, sum + memo[selected][i], i);
		}
		visited[selected] = false;
	}
}

int main(){ 
	cin >> R;
	routines.resize(R);
	memo.resize(R);
	for (int i = 0; i < R; i++){
		cin >> routines[i];
		memo[i].resize(R);
	}

	memorization();
	visited.resize(R, false);
	for (int i = 0; i < R; i++)
		DR(0, 0, i);
	cout << res << endl;
}
