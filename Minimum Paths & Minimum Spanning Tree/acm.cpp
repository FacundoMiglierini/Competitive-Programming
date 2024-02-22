#include <bits/stdc++.h>
using namespace std;

//Declaración de variables globales
int N, M, S1, S2;
vector<int> parents;
vector<int> used;
vector<pair<int, pair<int, int>>> edges;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> edges_sorter;

//Inicializa los conjuntos, colocando a cada vértice como su propio padre
void initialise(){
	parents.clear();
	for(int i = 0; i < N; i++)
		parents.push_back(i);
}

//Aplica Path compression para chequeos de pertenencia a conjuntos más eficientes
int pathCompression(int idx_parent){

	if(parents[idx_parent] != idx_parent)
		parents[idx_parent] = pathCompression(parents[idx_parent]);

	return parents[idx_parent];
}

//Búsqueda del padre de un conjunto
int findSet(int idx){
	int aux = idx;
	while(aux != parents[aux])
		aux = parents[aux];

	return aux;
}

//Cálculo del segundo mejor MST
int secondMST(){
	int sec_best_mst = INT_MAX;
	int mst_cost = 0;	
	int vi, vj, cost, pi, pj;
	int edg;

	//Se itera sobre las aristas usadas en el MST, y se ignora una de ellas en cada loop
	for(int j = 0; j < used.size(); j++){
		initialise();
		edg = 0;
		//Se recorren todas las aristas cargadas inicialmente
		for(int i = 0; i < M; i++){
			if(i == used[j])
				continue;

			vi = edges[i].second.first;
			vj = edges[i].second.second;
			cost = edges[i].first;

			pi = findSet(vi);
			pj = findSet(vj);

			//Si los vértices pertenecen a distintos conjuntos, se hace la unión y se suma el costo de la arista que comunica a ambos vértices
			if(pi != pj){
				mst_cost = mst_cost + cost;
				parents[pj] = pi;
				pathCompression(pj);
				edg++;
			}
		}

		//Se chequea si se logró tener conectividad para todos los vértices (N - 1 aristas)
		if(edg != N - 1){
			mst_cost = 0;
			continue;
		}

		//Se chequea si el árbol obtenido tiene costo menor al resto de árboles
		if(sec_best_mst > mst_cost)
			sec_best_mst = mst_cost;
		mst_cost = 0;
	}

	//Se retorna el segundo MST
	return sec_best_mst;
}

//Cálculo del MST
int MST(){
	int mst_cost = 0;	
	int vi, vj, cost, pi, pj;
	int counter = N - 1;
	int i = 0;

	//Se recorre las aristas hasta haber obtenido N - 1 y haber logrado la conectividad de todos los vértices
	while(counter != 0){
		vi = edges[i].second.first;
		vj = edges[i].second.second;
		cost = edges[i].first;

		pi = findSet(vi);
		pj = findSet(vj);

		//Se chequea si los vértices pertenecen al mismo conjunto, de ser así, se hace una unión y se suma el costo de la arista que une ambos vértices.
		if(pi != pj){
			//Se guarda la arista usada para luego calcular el segundo MST
			used.push_back(i);
			mst_cost = mst_cost + cost;
			parents[pj] = pi;
			pathCompression(pj);
			counter--;
		}
		i++;
	}

	//Se retorna el MST
	return mst_cost;
}

int main(){
	int T, A, B, C;
	cin >> T;

	//Itera sobre todos los casos
	for(int i = 0; i < T; i++){

		//Se recibe N, M y se inicializa la cola de prioridades del caso i
		cin >> N >> M;
		edges_sorter = priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>();

		//Se lee cada arista y se la encola a una cola de prioridades
		for(int j = 0; j < M; j++){
			cin >> A >> B >> C;
			pair<int, int> nodes = make_pair(A - 1, B - 1);
			edges_sorter.push(make_pair(C, nodes));
		}

		//Se copian los datos ordenados por la cola de prioridades en un vector
		for(int j = 0; j < M; j++){
			edges.push_back(edges_sorter.top());
			edges_sorter.pop();
		}

		//Se ejecuta el cálculo del MST y segundo MST
		initialise();
		S1 = MST();
		S2 = secondMST();

		//Se muestran los resultados en pantalla
		cout << S1 << " " << S2 << endl;

		//Se limpian los vectores para el próximo caso 
		edges.clear();
		used.clear();
	}
}
