#include <bits/stdc++.h>
using namespace std;

priority_queue<int> queue_p;
queue<int> queue_n;
stack<int> stack_n;
string line;
int operation, value, size;
bool queue_p, queue_n, stack_n;

int main(){
	while(cin >> N){
		queue_n.clear();
		stack_n.clear();
		queue_p.clear();
		
		priority = true;
		normal_q = true;
		stack_n = true;
		cin >> size;
		for(int i=1; i<=size, i++){
			normal_q = true;
			stack_n = true;
			stringstream ss(line);		
			ss >> operation >> value;
			if(operation == 1){
				queue_p.push(value);
				queue_n.push(value);
				stack_n.push(value);
			}
			else{
				if(priority && queue_p.pop() != value)
					priority = false;
				if(normal_q && queue_n.pop() != value)
					normal_q = false;
				if(stack_n && stack_n.pop() != value)
					stack_n = false;
			}

		}
		int valor = priority + normal_q + stack_n;
		if (valor == 0)
			cout << "impossible" << endl;
		else
			if (valor > 1) 
				cout << "not sure" << endl;
		else
			if (priority)
				cout << "priority queue" << endl;
			if (normal_q)
				cout << "queue" << endl;
			if (stack_n)
				cout << "stack" << endl;	
	}
}
