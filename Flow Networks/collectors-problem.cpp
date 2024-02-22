#include <bits/stdc++.h>
using namespace std;

int n, m;


//OBTIENE EL PESO MÍNIMO EN EL CAMINO DE AUMENTO, LO DECREMENTA EN ARCOS FORWARD E INCREMENTA EN ARCOS BACKWARD
int augment(vector<vector<int>> &graph,
            const vector<int> prev,
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

//RECORRIDOS BFS HASTA QUE NO SEA POSIBLE HALLAR UN CAMINO DE AUMENTO
int edmonds_karp(vector<vector<int>> &graph){

  int mf = 0;
  int next;
  
  while(true){
    queue<int> elements;
    elements.push(0);

    vector<int> prev(n + m + 1, -1);
    prev[0] = 0;

    while(!elements.empty()){

      next = elements.front();
      elements.pop();

      for(int i = 1; i < n + m + 1; ++i){
        if(graph[next][i] > 0 && prev[i] == -1){
          prev[i] = next;
          elements.push(i);
        }
      }
    }

    if(prev[n + m] == -1)
      break;

    mf += augment(graph, prev, INT_MAX, 0, n + m);
  }

  return mf;
}

//ENTRADA DE DATOS Y MUESTRA DE RESULTADOS
int main(){

  int T;
  int k;
  int sticker;
  int cases = 0;
  cin >> T;

  while (T != 0){
   
    cases++;
    cin >> n >> m;


     /*
      * BOB como source
      * aristas desde personas a stickers, y stickers a target
      * arista 1 a 0 desde stickers a personas que no tengan el mismo.
      */

    vector<vector<int>> graph(n + m + 1, vector<int>(n + m + 1, 0));
    for(int i = 0; i < n; i++){
      cin >> k;
      for(int j = 0; j < k; j++){
        cin >> sticker;
        graph[i][n + sticker - 1]++;
      }
    }


    for(int i = n; i < n + m; i++){
      for(int j = 1; j < n; j++){
        if(graph[j][i])
          graph[j][i]--;
        else
          graph[i][j] = 1;
      }
      graph[i][n + m] = 1;
    }


    cout << "Case #" << cases << ": " << edmonds_karp(graph) << endl;

    T--;
  }
}
