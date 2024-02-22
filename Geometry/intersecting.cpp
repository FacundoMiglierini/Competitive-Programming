#include <bits/stdc++.h>
using namespace std;

//Declaración de clases para puntos y líneas
class Point{
	public:
		double x;
		double y;
};

class Line{
	public:
		double a;
		double b;
		double c;
};

//Función que en base a dos puntos genera una línea
void points_to_line(Point p1, Point p2, Line& l){
	if (p1.x == p2.x){
		l.a = 1;
		l.b = 0;
		l.c = -(p1.x);
	}else{
		l.b = 1;
		l.a = -(p1.y - p2.y) / (p1.x - p2.x);
		l.c = -(l.a * p1.x) - (l.b * p1.y);
	}
}

//Función que retorna True si las dos líneas recibidas por parámetro son paralelas
bool parallel(Line l1, Line l2){
	return (abs(l1.a - l2.a) <= DBL_EPSILON && abs(l1.b - l2.b <= DBL_EPSILON));
}

//Función que retorna True si las dos líneas recibidas por parámetro son iguales
bool same_line(Line l1, Line l2){
	return parallel(l1, l2) && abs(l1.c - l2.c) <= DBL_EPSILON;
}

//Función que imprime en pantalla el resultado de la intersección entre dos líneas:
//"LINE": ambas líneas son iguales
//"NONE": las líneas son paralelas pero no iguales, por lo que nunca intersectan
//"POINT: x, y" las líneas intersectan en el punto x, y.
void intersection(Line l1, Line l2){
	if(same_line(l1, l2))
		cout << "LINE" << endl;
	else{
		if(parallel(l1, l2))
			cout << "NONE" << endl;
		else{
			Point p;
			p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
			if(abs(l1.b) > DBL_EPSILON)
				p.y = -(l1.a * p.x + l1.c) / l1.b;
			else
				p.y = -(l2.a * p.x + l2.c) / l2.b;
			cout << "POINT " << p.x << " " << p.y << endl;
		}
	}
}

//Carga de datos y llamados a funciones
int main(){
	int N;
	cin >> N;
	cout << "INTERSECTING LINES OUTPUT" << endl;
	cout << fixed;
	cout << setprecision(2);
	for(int i = 1; i <= N; i++){
		Point origen_1,origen_2,destino_1,destino_2;
		Line l1, l2;
		cin >> origen_1.x >> origen_1.y >> destino_1.x >> destino_1.y >> origen_2.x >> origen_2.y >> destino_2.x >> destino_2.y;
		points_to_line(origen_1, destino_1, l1);
		points_to_line(origen_2, destino_2, l2);
		intersection(l1, l2);
	}
	cout << "END OF OUTPUT" << endl;
}
