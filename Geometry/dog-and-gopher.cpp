#include <bits/stdc++.h>
using namespace std;

double x1, x2, y_uno, y2;

double distance(double x1, double y_uno, double x2, double y2){
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y_uno) * (y2 - y_uno));
}

bool shorter_distance_gopher(double x, double y){
	double dist_gopher = distance(x1, y_uno, x, y);
	double dist_dog = distance(x2, y2, x, y);

	return dist_gopher * 2 < dist_dog; 
}

int main(){
	int n;
	double x_hole, y_hole;
	bool exist;
	pair<double, double> escape;

	while(cin){
		cin >> n >> x1 >> y_uno >> x2 >> y2;
		exist = false;
		for(int i = 1; i <= n; i++){
			cin >> x_hole >> y_hole;
			if (not exist and shorter_distance_gopher(x_hole, y_hole)){
				exist = true;
				escape = make_pair(x_hole, y_hole);
			}
		}

		if(exist)
			cout << "The gopher can escape through the hole at (" << escape.first << "," << escape.second << ")." << endl;
		else
			cout << "The gopher cannot escape" << endl;
	}
}
