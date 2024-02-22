#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;

int s;
int t;
int c;
int nodes;

//ENCONTRAR EL PESO MÍNIMO EN EL CAMINO DE AUMENTO, INCREMENTARLO EN LOS ARCOS FORWARD Y DECREMENTARLO EN LOS ARCOS BACKWARD
int augment(const vector<int> &prev, int min_bandwidth, int target, int source){

    min_bandwidth = min(min_bandwidth, graph[prev[target]][target]);


    if (prev[target] != source)
      min_bandwidth = augment(prev, min_bandwidth, prev[target], source);

    graph[prev[target]][target] -= min_bandwidth;
    graph[target][prev[target]] += min_bandwidth;

    return min_bandwidth;
}

//RECORRIDOS BFS HASTA QUE NO EXISTAN CAMINOS DE AUMENTO
int edmonds_karp(){

  int mf = 0;
  int next;

  while(true){

    queue<int> elements;
    elements.push(s);

    vector<int> prev(nodes + 1, -1);
    prev[s] = s;


    while(!elements.empty()){
      
          
      next = elements.front();
      elements.pop();

      for(int i = 1; i <= nodes; ++i){
        if (graph[next][i] > 0 && prev[i] == -1){
          prev[i] = next;
          elements.push(i);
        }
      }
    }

    if (prev[t] == -1)
      break;

    mf += augment(prev, INT_MAX, t, s);

  }

  return mf;
}


//ENTRADA DE DATOS Y SALIDA DE RESULTADOS
int main(){
  int x, y, weight;
  int cases = 1;

  while(cin >> nodes, nodes != 0){

    cin >> s >> t >> c;

    graph.clear();
    graph.resize(nodes + 1, vector<int>(nodes + 1, 0));

    for (int i = 0; i < c; i++){
      cin >> x >> y >> weight;
      graph[x][y] += weight;
      graph[y][x] += weight;
    }


    cout << "Network " << cases++ << endl;
    cout << "The bandwidth is " << edmonds_karp() << "." << endl;
    cout << endl;
  }
}
