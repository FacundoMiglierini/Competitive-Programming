#include<bits/stdc++.h>
using namespace std;

//Declaración de variables globales
vector<vector<bool>> dependencies;
vector<int> counter;
vector<bool> visited;

int N, T, aux;

//DFS sobre matriz de adyacencias
void dfs(int j){ 
	visited[j] = true;
	for(int i = 0; i < N; i++){
		if(dependencies[j][i] && not visited[i])
			dfs(i);
	}
}

int main(){
	//Lectura de N
	cin >> N;

	//Itera sobre distintos casos de prueba hasta recibir N = 0
	while(N != 0){
		dependencies.resize(N);
		counter.resize(N, 0);

		//Carga del aristas sobre matriz de adyacencias
		for(int j = 0; j < N; j++){
			cin >> T;
			dependencies[j].resize(N, false);
			for(int k = 0; k < T; k++){
				cin >> aux;
				dependencies[j][aux - 1] = true;
			}

		}

		//Se cuenta la cantidad de vértices visitados, comenzando desde cada vértice
		for(int j = 0; j < N; j++){
			visited.resize(N, false);
			dfs(j); 
			counter[j] = count(visited.begin(), visited.end(), true) - 1;
			visited.clear();
		}

		//Se calcula el máximo entre la cantidad de vértices visitados por cada vértice
		int max = -1;
		int maxPos = -1;
		for(int j = 0; j < N; j++){
			if(counter[j] > max){
				max = counter[j];
				maxPos = j + 1;
			}
		}

		//Muestra del resultado en pantalla
		cout << maxPos << endl;

		//Limpieza de variables para próxima iteración
		dependencies.clear();

		//Lectura de nuevo N
		cin >> N;
	}
}
