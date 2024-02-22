#include <bits/stdc++.h>
using namespace std;

//Declaración de clase para representar puntos
class Point{
	public:
		double x;
		double y;
};

//Declaración de variables globales
vector<Point> points;
int N;

//Función que retorna la distancia entre dos puntos
double distance(Point p1, Point p2){
	return sqrt(pow(abs(p1.x - p2.x), 2) + pow(abs(p1.y - p2.y), 2));
}

//Función que retorna la distancia más corta entre todos los puntos
double shorter_distance(){
	double MIN_DISTANCE = 40000;	
	double act_dist;
	for (int i = 0; i < N; i++){
		for (int j = i + 1; j < N; j++){
			act_dist = distance(points[i], points[j]);
			if (act_dist < MIN_DISTANCE)
				MIN_DISTANCE = act_dist;
		}
	}

	return MIN_DISTANCE;
}

//Carga de datos y llamado a funciones
int main(){
	double distance;
	cin >> N;
	cout << fixed;
	cout << setprecision(4);
	while(N != 0){
		points.clear();
		points.resize(N);
		for(int i = 0; i < N; i++)
			cin >> points[i].x >> points[i].y;
		
		double distance = shorter_distance();
		if (distance >= 10000)
			cout << "INFINITY" << endl;
		else
			cout << distance << endl;
		cin >> N;
	}
}
