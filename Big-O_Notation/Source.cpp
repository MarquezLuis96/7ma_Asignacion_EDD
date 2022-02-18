//Librerías
#include <iostream>
#include <string>

//Declaración de namespaces y namespaces members
using namespace std;

/* Convierte todas las letras de la string recibida en minúsculas
*/
string toLowerCase(string str) {
	// Recorriendo cada letra dentro del arreglo
	for (unsigned int i = 0; i < str.length(); i++) {
		// Cambiando de mayúscula a minúscula
		str[i] = tolower(str[i]);
	}

	//Retornando el resultado
	return str;
}

/* Convierte todas las letras de la string recibida en mayúsculas
*/
string toUpperCase(string str) {
	// Recorriendo cada letra dentro del arreglo
	for (unsigned int i = 0; i < str.length(); i++) {
		// Cambiando de minúscula a mayúscula
		str[i] = toupper(str[i]);
	}

	//Retornando el resultado
	return str;
}

/* Capitaliza la string recibida, transforma en mayúsculas su primera letra
*/
string capitalize(string str) {
	// Capitalizando la primera letra del string
	str[0] = toupper(str[0]);

	//Retornando el resultado
	return str;
}

/*	Esta función se encarga de confirmar si el string recibido es palindrome o no de forma óptima
*/
bool palindromeCheck(string str) {
	/*	Se recorre la mitad de la longitud del arreglo ya que se busca reducir la cantidad de iteraciones
	* con la ayuda de una variable 'last', la cual estará siendo utilizada para acceder a la posición n-i-1
	* del arreglo, recorriendo a la vez de forma ascendente y descendente el mismo.
	*/
	for (unsigned int i = 0; i < str.length() / 2; i++) {
		int last = str.length() - i - 1;
		if (str[i] == str[last]) {
			//Pasa a la siguiente iteración
			continue;
		}
		else {
			//La palabra no es palindroma
			return false;
		}
	}

	//La palabra es palindroma
	return true;
}

/* Esta función se encarga de llamar a todas las operaciones para comprobar si un string
* ingresado es o no palindromo
*/
void palindrome() {
	//Declarando la variable en la que se almacenará la palabra
	string word;

	// Ingresando la palabra a evaluar
	cout << "Ingrese un string (palabra o numero) para saber si es palindromo o no." << endl;
	cout << "String: ";
	cin >> word;
	cout << endl;

	/* Pasando a lower case para que al momento de comparar no se tengan problemas de comparación
	* ocasionados por la diferencia entre mayúsculas y minúsculas
	*/
	word = toLowerCase(word);

	if (palindromeCheck(word)) {
		//Si la palabra es palíndroma
		//Capitaliza la palabra
		word = capitalize(word);
		//Imprime el resultado
		cout << "El string  '" << word << "' es palindromo." << endl;
	}
	else {
		//Si la palabra no es palíndroma
		//Capitaliza la palabra
		word = capitalize(word);
		//Imprime el resultado
		cout << "El string '" << word << "' no es palindromo." << endl;
	}
}

//Función principal
int main(int args, const char* argsv[]) {
	palindrome();
	return 0;
}