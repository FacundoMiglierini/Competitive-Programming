#include <bits/stdc++.h>
using namespace std;


int main(){
	set<int> idsN, idsM, result;
	int N, M, number;

	cin >> N >> M;
	while (N != 0 && M != 0){
		idsN.clear();
		idsM.clear();
		result.clear();

		for(int i = 1; i <= N; i++){
			cin >> number;
			idsN.insert(number);
		}
		for(int i = 1; i <= M; i++){
			cin >> number;
			idsM.insert(number);
		}
		
		set_intersection(idsN.begin(), idsN.end(), idsM.begin(), idsM.end(), inserter(result, result.begin()));
		cout << result.size() << endl;
		cin >> N >> M;
	}
}
