//Librer�as
#include <iostream>
#include <string>

//Declaraci�n de namespaces y namespaces members
using namespace std;

/* Convierte todas las letras de la string recibida en min�sculas
*/
string toLowerCase(string str) {
	// Recorriendo cada letra dentro del arreglo
	for (unsigned int i = 0; i < str.length(); i++) {
		// Cambiando de may�scula a min�scula
		str[i] = tolower(str[i]);
	}

	//Retornando el resultado
	return str;
}

/* Convierte todas las letras de la string recibida en may�sculas
*/
string toUpperCase(string str) {
	// Recorriendo cada letra dentro del arreglo
	for (unsigned int i = 0; i < str.length(); i++) {
		// Cambiando de min�scula a may�scula
		str[i] = toupper(str[i]);
	}

	//Retornando el resultado
	return str;
}

/* Capitaliza la string recibida, transforma en may�sculas su primera letra
*/
string capitalize(string str) {
	// Capitalizando la primera letra del string
	str[0] = toupper(str[0]);

	//Retornando el resultado
	return str;
}

/*	Esta funci�n se encarga de confirmar si el string recibido es palindrome o no de forma �ptima
*/
bool palindromeCheck(string str) {
	/*	Se recorre la mitad de la longitud del arreglo ya que se busca reducir la cantidad de iteraciones
	* con la ayuda de una variable 'last', la cual estar� siendo utilizada para acceder a la posici�n n-i-1
	* del arreglo, recorriendo a la vez de forma ascendente y descendente el mismo.
	*/
	for (unsigned int i = 0; i < str.length() / 2; i++) {
		int last = str.length() - i - 1;
		if (str[i] == str[last]) {
			//Pasa a la siguiente iteraci�n
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

/* Esta funci�n se encarga de llamar a todas las operaciones para comprobar si un string
* ingresado es o no palindromo
*/
void palindrome() {
	//Declarando la variable en la que se almacenar� la palabra
	string word;

	// Ingresando la palabra a evaluar
	cout << "Ingrese un string (palabra o numero) para saber si es palindromo o no." << endl;
	cout << "String: ";
	cin >> word;
	cout << endl;

	/* Pasando a lower case para que al momento de comparar no se tengan problemas de comparaci�n
	* ocasionados por la diferencia entre may�sculas y min�sculas
	*/
	word = toLowerCase(word);

	if (palindromeCheck(word)) {
		//Si la palabra es pal�ndroma
		//Capitaliza la palabra
		word = capitalize(word);
		//Imprime el resultado
		cout << "El string  '" << word << "' es palindromo." << endl;
	}
	else {
		//Si la palabra no es pal�ndroma
		//Capitaliza la palabra
		word = capitalize(word);
		//Imprime el resultado
		cout << "El string '" << word << "' no es palindromo." << endl;
	}
}

//Funci�n principal
int main(int args, const char* argsv[]) {
	palindrome();
	return 0;
}