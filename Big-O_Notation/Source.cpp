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

/*	Esta funci�n se encarga de confirmar si el string recibido es palindrome o no
*	
*	La complejidad de este algoritmo es de O(n/2) ya que el ciclo se repite la mitad
* de veces de cuantas letras tenga la palabra.
* 
*/
bool palindromeCheck(string str) {
	/*	Se recorre la mitad de la longitud del arreglo ya que se busca reducir la cantidad de iteraciones
	* con la ayuda de una variable 'last', la cual estar� siendo utilizada para acceder a la posici�n n-i-1
	* del arreglo, recorriendo a la vez de forma ascendente y descendente el mismo.
	*/
	for (unsigned int i = 0; i < str.length() / 2; i++) {	// O(n/2)
		int last = str.length() - i - 1;					// O(1)
		if (str[i] == str[last]) {							// O(1)
			//Pasa a la siguiente iteraci�n
			continue;										// O(1)
		}
		else {												// O(1)
			//La palabra no es palindroma
			return false;									// O(1)
		}
	}

	//La palabra es palindroma
	return true;											// O(1)
}

/* Esta funci�n se encarga de llamar a todas las operaciones para comprobar si un string
* ingresado es o no palindromo
*/
void palindrome() {
	//Declarando la variable en la que se almacenar� la palabra
	string word;

	// Ingresando la palabra a evaluar
	cout << "Ingrese una palabra para saber si es palindroma o no." << endl;
	cout << "Palabra: ";
	cin >> word;
	cout << endl;

	/* Pasando a lower case para que al momento de comparar no se tengan problemas de comparaci�n
	* ocasionados por la diferencia entre may�sculas y min�sculas
	*/
	word = toLowerCase(word);

	if (palindromeCheck(word)) {
		//Si la palabra es pal�ndroma entra ac�
		//Capitaliza la palabra
		word = capitalize(word);
		//Imprime el resultado
		cout << "La palabra  '" << word << "' es palindroma." << endl << endl;
	}
	else {
		//Si la palabra no es pal�ndroma entra ac�
		//Capitaliza la palabra
		word = capitalize(word);
		//Imprime el resultado
		cout << "La palabra '" << word << "' no es palindroma." << endl << endl;
	}
}

/* Esta estructura contendr� una letra y el n�mero de veces que esta aparece en una palabra.
* Se usar� principalmente para crear un arreglo
*/
struct occurrence {
	private:
		char letra = ' ';
		int veces = 0;

	public:
		void incrementVeces() {
			veces++;
		}

		int getVeces() {
			return veces;
		}
		
		void setLetra(char letter) {
			letra = letter;
			incrementVeces();
		}

		char getLetra() {
			return letra;
		}
};

/* Esta funci�n es la encargada de contar todas las ocurrencias de un caracter (letra o n�mero)
* recibe como par�metros un string word que ser� la palabra a la que se le cuenten las ocurrencias
* y recibe un arreglo de la estructura occurrence, que es donde se almacenar�n las letras y las ocurrencias correspondientes
* 
* El orden de este algoritmo es O(n^2) ya que siempre se pasa por el ciclo for de la l�nea 144 n veces
* El ciclo do-while de la l�nea 153 en el peor de los casos (que todas las letras sean distintas) se ejecuta n veces
* 
* teniendo en cuenta esto se puede decir que el algoritmo es de complejidad O(n^2)
* 
*/
void countOccurrences(string word, occurrence letras[]) {
	//Se utiliza este ciclo para recorrer cada posici�n dentro de la palabra
	for (unsigned int i = 0; i < word.length(); i++) {																	//O(n)
		//Se declara la variable pos, la cu�l ayudar� a movernos en la posici�n del arreglo letras
		int pos = 0;																									//O(1)

		/* Con el siguiente ciclo do-while estaremos desplaz�ndonos entre las posiciones del arreglo letras
		* la condici�n del while es true ya que as� nos ahorramos el declarar una variable bandera y adem�s
		* de que las sentencias dentro del mismo bucle do-while indican cuando salirse del ciclo.
		* (Cuando se agregue una nueva letra y cuando se incremente el contador de alguna letra)
		*/
		do {																											//O(n)
			if (letras[pos].getLetra() == ' ') {																		//O(1)
				/* Se entrar� ac� si el espacio dentro del arreglo est� en blanco, es decir, no se hall� la letra de
				* la palabra y se procede a agregarla
				*/
				letras[pos].setLetra(word[i]);																			//O(1)
				break;																									//O(1)
			}
			else {																										//O(1)
				if (word[i] == letras[pos].getLetra()) {																//O(1)
					/* Se entrar� ac� si se hall� una nueva ocurrencia y se incrementar� el contador para dicha letra
					*/
					letras[pos].incrementVeces();																		//O(1)
					break;																								//O(1)
				}
				else {																									//O(1)
					/* Se entrar� ac� cuando no se haya encontrado una nueva ocurrencia y la posici�n actual del arreglo letras
					* sea diferente a espacio en blanco
					*/
					pos++;																								//O(1)
				}
			}
		} while (true);
	}
}


/* Esta funci�n se encarga de imprimir el arreglo que contiene las letras con su n�mero de ocurrencias
*/
void printOccurrences(occurrence letras[]) {
	int i = 0;
	int totalLetras = 0;
	while (letras[i].getLetra() != ' ') {
		cout << letras[i].getLetra() << " = " << letras[i].getVeces() << endl;
		totalLetras += letras[i].getVeces();
		i++;
	}

	cout << endl << "Total de caracteres: " << totalLetras << endl;
}

/* Esta funci�n se encarga de llamar a todas las operaciones para contar las
* ocurrencias de una letra o digito en un string
*/
void occurrences() {
	//Declarando la variable en la que se almacenar� la palabra
	string word;

	/* Declarando un arreglo en el que se almacenar�n las ocurrencias
	* Se declara de 28 posiciones ya que 27 letras son las que existen en el alfabeto espa�ol
	*/
	occurrence letras[28];

	// Ingresando la palabra a evaluar
	cout << "Ingrese una palabra para saber el numero de ocurrencias de cada caracter." << endl;
	cout << "String: ";
	cin >> word;
	cout << endl;

	/* Pasando a lower case para que al momento de comparar no se tengan problemas de comparaci�n
	* ocasionados por la diferencia entre may�sculas y min�sculas
	*/
	word = toUpperCase(word);

	countOccurrences(word, letras);

	cout << "El numero de ocurrencias para cada letra de la palabra ' " << word << " ' es:" << endl << endl;
	printOccurrences(letras);
}

//Funci�n principal
int main(int args, const char* argsv[]) {

	char opc;

	cout << "Bienvenida... " << endl << endl;
	
	do {
		cout << "Seleccione: " << endl;
		cout << "1 - Para comprobar si una palabra es palindroma o no. " << endl;
		cout << "2 - Para contar el numero de ocurrencias de cada caracter dentro de una palabra. " << endl;
		cout << "0 - Para salir. " << endl << endl;
		cout << "Opcion: ";
		cin >> opc;
		cout << endl;

		switch (opc) {
			case '0':
				cout << "Hasta luego..." << endl;
				break;

			case '1':
				palindrome();
				break;

			case '2':
				occurrences();
				break;

			default:
				cout << "Opcion invalida. Intente de nuevo." << endl;
				continue;
		}
	} while (opc != '0');
	return 0;
}