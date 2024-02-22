#include<bits/stdc++.h>
using namespace std;

int N;
int M;

//ENCONTRAR EL PESO MÍNIMO EN EL CAMINO DE AUMENTO, INCREMENTARLO EN LOS ARCOS FORWARD Y DECREMENTARLO EN LOS BACKWARD
int augment(vector<vector<int>> &graph,
            const vector<int> &prev,
            int min_mf,
            int source,
            int target){

  min_mf = min(min_mf, graph[prev[target]][target]);

  if(prev[target] != source)
    min_mf = augment(graph, prev, min_mf, source, prev[target]);

  graph[prev[target]][target] -= min_mf;
  graph[target][prev[target]] += min_mf;

  return min_mf;
}


//RECORRIDOS BFS HASTA QUE NO EXISTAN CAMINOS DE AUMENTO
int edmonds_karp(vector<vector<int>> &graph){

  int mf = 0;
  int next;


  while(true){
    queue<int> elements;
    elements.push(0);

    vector<int> prev(M + 6 + 2, -1);
    prev[0] = 0;

    while(!elements.empty()){

      next = elements.front();
      elements.pop();

      for(int i = 1; i <= M + 6 + 1; ++i){
        if(graph[next][i] > 0 && prev[i] == -1){
          prev[i] = next;
          elements.push(i);
        }
      }

    }

    if(prev[M + 6 + 1] == -1)
      break;

    mf += augment(graph, prev, INT_MAX, 0, M + 6 + 1);
  }


  return mf;
}


//ENTRADA DE DATOS Y SALIDA DE RESULTADOS
int main(){
  int T;
  map <string, int> talles;
  string talle1, talle2;

  talles["XS"] = 1;
  talles["S"] = 2;
  talles["M"] = 3;
  talles["L"] = 4;
  talles["XL"] = 5;
  talles["XXL"] = 6;

  cin >> T;

  while(T > 0){
    
    cin >> N >> M;

    vector<vector<int>> graph(M + 6 + 2, vector<int>(M + 6 + 2, 0));

    //CAPACIDAD DESDE EL SOURCE A CADA TALLE 
    for(int i = 1; i <= 6; i++)
      graph[0][i] = N / 6;

    //CAPACIDAD DESDE CADA TALLE A CADA PERSONA
    for(int i = 1; i <= M; i++){
      cin >> talle1 >> talle2;

      graph[talles[talle1]][i + 6] = 1;
      graph[talles[talle2]][i + 6] = 1; 


      //CAPACIDAD DESDE CADA PERSONA AL TARGET
      graph[i + 6][M + 6 + 1] = 1; 
    }

    if (edmonds_karp(graph) >= M)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;

    T--;
  }
}
