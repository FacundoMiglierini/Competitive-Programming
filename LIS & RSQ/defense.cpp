#include <bits/stdc++.h>
using namespace std;


int lis(vector<int> &v, vector<int> &DP, vector<int> &prev, int idx){

	if(DP[idx] != -1)
		return DP[idx];

	DP[idx] = 1;
	prev[idx] = -1;

	for (int i = 0; i < idx; i++){
		if(lis(v, DP, prev, i) + 1 > DP[idx] && v[i] < v[idx]){
			DP[idx] = lis(v, DP, prev, i) + 1;
			prev[idx] = i;
		}
	}

	
	return DP[idx];
}


int main(){
	vector<int> v;
	vector<int> DP;
	vector<int> prev;
	stack<int> stack;

	int valor;
	int testCases;

	string blank;
	string input;
	stringstream ss;

	getline(cin, input);
	ss.str(input);
	ss >> testCases;
	
	getline(cin, input);

	for (int i = 0; i < testCases; i++){
		v.clear();
		DP.clear();
		prev.clear();

		getline(cin, input);
		while (input != ""){
			ss.clear();	
			ss.str(input);
			ss >> valor;
			v.push_back(valor);
			getline(cin, input);
		}

		DP.resize(v.size(), -1);
		prev.resize(v.size(), -1);

		lis(v, DP, prev, v.size() - 1);
		int max = *max_element(DP.begin(), DP.end());
		int max_pos = distance(DP.begin() , max_element(DP.begin(), DP.end()));

		cout << "Max hits: " << max << endl;

		int list = max_pos;
		while(list != -1){
			stack.push(list);
			list = prev[list];
		}

		while(!stack.empty()){
			int number = stack.top();
			stack.pop();
			cout << v[number] << endl;
		}

		if(i != (testCases - 1)) 
				cout << endl;
	}


}
