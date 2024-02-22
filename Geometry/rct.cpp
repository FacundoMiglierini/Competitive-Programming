#include <bits/stdc++.h>
using namespace std;

//Declaración de clases
class Point{
	public:
		double x;
		double y;
};

class Figure{
	public:
		virtual bool contains(Point p) = 0;
};

class Rectangle: public Figure{
		Point upper_left;
		Point lower_right;
		
	public:
		Rectangle()
		{
			cin >> upper_left.x >> upper_left.y >> lower_right.x >> lower_right.y;
		}

		bool contains(Point p) override {
			return (p.x > upper_left.x && p.x < lower_right.x) && (p.y < upper_left.y && p.y > lower_right.y); 
		}
};

class Circle: public Figure{
		Point center;
		double radius;


	public:
		Circle()
		{
			cin >> center.x >> center.y >> radius;
		}

		bool contains(Point p) override {
			return sqrt(pow(abs(center.x - p.x), 2) + pow(abs(center.y - p.y), 2)) < radius;
		}
};

class Triangle: public Figure{
		Point v1;
		Point v2;
		Point v3;

		double sign(Point v1, Point v2, Point v3){
			return (v1.x - v3.x) * (v2.y - v3.y) - (v2.x - v3.x) * (v1.y - v3.y);
		}

	public:
		Triangle()
		{
			cin >> v1.x >> v1.y >> v2.x >> v2.y >> v3.x >> v3.y;
		}

		bool contains(Point p) override {
			bool has_negative, has_positive;
			double d1, d2, d3;

			d1 = sign(p, v1, v2);
			d2 = sign(p, v2, v3);
			d3 = sign(p, v3, v1);

			has_negative = (d1 < 0) || (d2 < 0) || (d3 < 0);
			has_positive = (d1 > 0) || (d2 > 0) || (d3 > 0);

			return !(has_negative && has_positive);
		}
};

//Carga de datos y muestra de resultados
int main(){
	bool end = false;
	char type;
	vector<Figure*> figures;

	while(not end){
		cin >> type;
		switch(type){
			case 'r': 
				{
					figures.push_back(new Rectangle());
					break;
				}
			case 'c':
				{
					figures.push_back(new Circle());
					break;
				}
			case 't':
				{
					figures.push_back(new Triangle());
					break;
				}
			default:
				end = true;
				break;
		}
	}
	end = false;
	Point p;
	int counter = 0;
	while(not end){
		cin >> p.x >> p.y;	
		if(p.x == 9999.9 and p.y == 9999.9)
			end = true;
		else{
			counter++;
			int cant = 0;
			for(int i = 0; i < figures.size(); i++){
				if(figures[i]->contains(p)){
					cout << "Point " << counter << " is contained in figure " << i + 1 << endl;
					cant++;
				}
			}
			if(cant == 0)
				cout << "Point " << counter << " is not contained in any figure" << endl;
		}
	}
}
