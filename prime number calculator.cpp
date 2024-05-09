#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

/* Este programa utiliza um vetor de n�meros primos. Para checar se um n�mero � primo, ele divide cada n�mero pelos membros
do vetor de primos que s�o menores ou iguais � raiz quadrada do n�mero.*/

void calcular(unsigned long long); //calcula todos

void expandir(unsigned long long*&, long&); //expande vetor

int main(int argc, char** argv) //para receber os n�meros direto
{
	system("pause");
	if (argv[1] && atoll(argv[1])) //verifica se o programa recebeu um argumento e se o mesmo � um n�mero
	{
		unsigned long long x = atoll(argv[1]); //x � igual a argv convertido em long long
		switch (x)
		{
		case 0:
		case 1:
			cout << "N�o h� primos!"; break;
		default:
			calcular(x);
		}
	}
	else { cout << "Argumento inexistente ou inv�lido!  "; }
	cout << "\b\b "; //exclui a v�rgula ap�s o �ltimo n�mero
}

void calcular(unsigned long long x)
{
	long tamvet = 1; //tamanho do vetor
	unsigned long long* v = new unsigned long long[tamvet]; //vetor de n�meros primos
	long cont = 0; //quantidade de elementos
	long cont2 = 0; //quantidade de elementos menores ou iguais � raiz quadrada do n�mero
	int isprime = 0;

	for (unsigned long long i = 2; i <= x; i++) //testa os inteiros at� x
	{
		cont = cont; cont2 = cont2;
		if (sqrt(i) >= v[cont2]) { cont2++; } // aumenta cont2 se a raiz quadrada de i for maior que v[cont2]
		for (long j = 0; j < cont2; j++)
		{
			if ((i % v[j]) == 0) { isprime++; } //verifica se i � divis�vel por membros de v
		}
		if (isprime == 0)
		{
			v[cont] = i; //coloca o n�mero primo no vetor
			cout << i << ", "; //imprime o n�mero
			cont++; //aumenta o contador de primos
			if (cont == tamvet)
			{
				expandir(v, tamvet); //duplica o tamanho do vetor
			}
		}
		isprime = 0; //reseta isprime
	}

	/*for (long i = 0; i < cont; i++)
	{
		cout << v[i] << ", ";
	}
	delete[] v; */
}

void expandir(unsigned long long*& vetor, long& l) //recebe uma refer�ncia de ponteiro e de long
{
	l *= 2; //duplica a vari�vel de tamanho do vetor
	unsigned long long* w = new unsigned long long[l]; //cria um vetor tempor�rio
	for (long i = 0; i < (l / 2); i++) { w[i] = vetor[i]; }; //copia os dados do vetor antigo para o tempor�rio
	delete[] vetor; //exclui o vetor original
	vetor = w; //recria e atribui o vetor de volta
}

