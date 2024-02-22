#include <bits/stdc++.h>
using namespace std;

//declaración del diccionario
map<string,string> diccionario;
//lectura de palabras
string palabra, line;
int main(){
	//carga del diccionario
	string palabra_ingles, palabra_otro;

	getline(cin, line);
	while(line != ""){
		stringstream ss(line);

		ss >> palabra_ingles >> palabra_otro;
		diccionario[palabra_otro] = palabra_ingles;

		getline(cin, line);
	}
	
	//traducción
	while(cin >> palabra){
		if (diccionario.count(palabra))
			cout << diccionario[palabra] << endl;
		else
			cout << "eh" << endl;
	}

	return 0;
}
