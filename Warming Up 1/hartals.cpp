#include <cstdio>
#include <vector>
#include <bits/stdc++.h>

int main(){
	int T, N, P, h, x;
	std::vector<bool> singleCase;
	std::vector<int> result;

	std::scanf("%i", &T);
	result.resize(T, 0);

	for(int counter=0; counter<T; counter++){
		std::scanf("%i", &N);
		singleCase.clear();
		singleCase.resize(N, false);
		std::scanf("%i", &P);
		for (int i=0; i<P; i++){
			std::scanf("%i", &h);
			x = h;
			while (x <= N){
				if (x % 7 != 6 && x % 7 != 0)
					singleCase[x - 1] = true;
				x += h;
			}
		}
		result[counter] = count(singleCase.begin(), singleCase.end(), true); 
	}
	for(const int &res : result){
		std::printf("%d\n", res);
	}
}
