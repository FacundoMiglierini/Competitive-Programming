#include <bits/stdc++.h>
using namespace std;

//Declaración de variables globales
int n, m, S, T;
vector<vector<pair<int, int>>> servers;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> dw;
vector<int> costos;
vector<bool> conocido;

//Cálculo de Dijkstra
int dijkstra(){
	for(int i = 0; i < 2*m; i++){

		//Se extrae el vértice con distancia mínima de la iteración i
		int minPos = dw.top().second;
		costos[minPos] = dw.top().first;
		dw.pop();
		conocido[minPos] = true;

		//Cuando se encuentra el destino, finaliza la iteración
		if(minPos == T)
			break;

		//Se recorren los vértices conectados al vértice mínimo de la iteración i
		for(int j = 0; j < servers[minPos].size(); j++){
			//Si el vértice "j" aún no fue recorrido y su distancia es mayor a la distancia del vértice mínimo sumada a una arista entre ambos, se actualiza la distancia de "j" y se inserta de forma ordenada en una cola de prioridades 
			if(not conocido[servers[minPos][j].first] && costos[servers[minPos][j].first] > costos[minPos] + servers[minPos][j].second){
				costos[servers[minPos][j].first] = costos[minPos] + servers[minPos][j].second;
				dw.push(make_pair(costos[servers[minPos][j].first], servers[minPos][j].first));
			}
		}
	}

	//Se retorna la distancia mínima desde el origen S al destino T
	return costos[T];
}

int main(){
	int N, s1, s2, w;	
	cin >> N;

	//Se itera sobre N casos de prueba
	for(int i = 1; i <= N; i++){

		//Lectura de datos e inicialización de variables
		cin >> n >> m >> S >> T;
		servers.resize(n);
		conocido.resize(n, false);
		costos.resize(n, INT_MAX);
		dw = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>>();

		//Carga de aristas con peso en lista de adyacencias
		for(int j = 0; j < m; j++){
			cin >> s1 >> s2 >> w;	
			servers[s1].push_back(make_pair(s2, w));
			servers[s2].push_back(make_pair(s1, w));
		}

		//Comienza ejecución del cálculo de Dijkstra
		costos[S] = 0;
		dw.push(make_pair(0, S));

		int res = dijkstra();

		//Muestra del resultado para el caso "i"
		cout << "Case #" << i << ": ";
		if(res != INT_MAX)
			cout << res << endl;
		else
			cout << "unreachable" << endl;

		//Limpio variables para próximo caso de prueba
		servers.clear();
		conocido.clear();
		costos.clear();
	}
}
