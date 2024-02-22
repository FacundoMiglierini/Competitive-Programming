#include <bits/stdc++.h>
using namespace std;

vector<int> tower1, tower2;
int h1, h2, height, counter;

int lcs(){
	int n = tower1.size() + 1, m = tower2.size() + 1, i, j;
	int memo[n][m];	
	
	for(i = 1; i < n; i++)
		memo[i][0] = 0;
	for(i = 1; i < m; i++)
		memo[0][i] = 0;

	for(i = 1; i < n; i++){
		for(j = 1; j < m; j++){
			if(tower1[i - 1] == tower2[j - 1])
				memo[i][j] = memo[i - 1][j - 1] + 1;
			else
				memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
		}
	}
	return memo[n - 1][m - 1];

}


int main(){
	counter = 1;
	while (true){
		cin >> h1 >> h2;
		if (h1 == 0 && h2 == 0)
			break;

		for(int i = 0; i < h1; i++){
			cin >> height;
			tower1.push_back(height);
		}
		for(int i = 0; i < h2; i++){
			cin >> height;
			tower2.push_back(height);
		}
		
		cout << "Twin Towers #" << counter++ << endl;
		cout << "Number of Tiles : " << lcs() << endl;
		cout << endl;

		tower1.clear();
		tower2.clear();
	}
}
