#include <bits/stdc++.h>
using namespace std;

int main(){
	int number;
	map<int, int> ocurrences;
	vector<int> insertOrder;

	while (cin >> number){
		ocurrences[number]++;
		if (!count(insertOrder.begin(), insertOrder.end(), number)){
			insertOrder.push_back(number);
		}
	}

	for (int i = 0; i < insertOrder.size(); i++){
		cout << insertOrder[i] << " " << ocurrences[insertOrder[i]] << endl;
	}
	
	return 0;
}
