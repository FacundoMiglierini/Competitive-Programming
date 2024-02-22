#include <bits/stdc++.h>
using namespace std;

vector<int> bars;
int t;
int p;
int n;

int knapsack(){
	int DP[p + 1][n + 1];

	for (int i = 0; i <= p; i++)
		DP[i][0] = 0;
	for (int j = 0; j <= n; j++)
		DP[0][j] = 0;
	for (int i = 1; i <= p; i++){
		for (int j = 1; j <= n; j++){
			if (bars[i - 1] > j) 
				DP[i][j] = DP[i - 1][j];
			else
				DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - bars[i - 1]] + bars[i - 1]);
		}
	}

	return DP[p][n];
}

int main(){
	cin >> t;
	for (int i = 0; i < t; i++){
		cin >> n;
		cin >> p;
		bars.resize(p);
		for (int j = 0; j < p; j++)
			cin >> bars[j];
	
		if (knapsack() == n)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		
		bars.clear();
	}
}
