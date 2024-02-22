#include <bits/stdc++.h>
using namespace std;

string seq1, seq2;

int lcs(){
	int n = seq1.length() + 1, m = seq2.length() + 1, memo[n][m];

	for(int i = 0; i < n; i++) 
		memo[i][0] = 0;
	for(int j = 0; j < m; j++)
		memo[0][j] = 0;

	for(int i = 1; i < n; i++){
		for(int j = 1; j < m; j++){
			if(seq1[i - 1] == seq2[j - 1])
				memo[i][j] = memo[i - 1][j - 1] + 1;
			else
				memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
		}
	}

	return memo[n - 1][m - 1];

}

int main(){
	int d = 0;
	getline(cin, seq1);
	while(seq1 != "#"){
		d++;
		getline(cin, seq2);
		
		
		cout << "Case #" << d << ": you can visit at most " << lcs() << " cities." << endl;

		getline(cin, seq1);
	}
}
