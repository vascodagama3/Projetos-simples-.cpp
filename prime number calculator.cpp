#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

/* Este programa utiliza um vetor de números primos. Para checar se um número é primo, ele divide cada número pelos membros
do vetor de primos que são menores ou iguais à raiz quadrada do número.*/

void calcular(unsigned long long); //calcula todos

void expandir(unsigned long long*&, long&); //expande vetor

int main(int argc, char** argv) //para receber os números direto
{
	system("pause");
	if (argv[1] && atoll(argv[1])) //verifica se o programa recebeu um argumento e se o mesmo é um número
	{
		unsigned long long x = atoll(argv[1]); //x é igual a argv convertido em long long
		switch (x)
		{
		case 0:
		case 1:
			cout << "Não há primos!"; break;
		default:
			calcular(x);
		}
	}
	else { cout << "Argumento inexistente ou inválido!  "; }
	cout << "\b\b "; //exclui a vírgula após o último número
}

void calcular(unsigned long long x)
{
	long tamvet = 1; //tamanho do vetor
	unsigned long long* v = new unsigned long long[tamvet]; //vetor de números primos
	long cont = 0; //quantidade de elementos
	long cont2 = 0; //quantidade de elementos menores ou iguais à raiz quadrada do número
	int isprime = 0;

	for (unsigned long long i = 2; i <= x; i++) //testa os inteiros até x
	{
		cont = cont; cont2 = cont2;
		if (sqrt(i) >= v[cont2]) { cont2++; } // aumenta cont2 se a raiz quadrada de i for maior que v[cont2]
		for (long j = 0; j < cont2; j++)
		{
			if ((i % v[j]) == 0) { isprime++; } //verifica se i é divisível por membros de v
		}
		if (isprime == 0)
		{
			v[cont] = i; //coloca o número primo no vetor
			cout << i << ", "; //imprime o número
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

void expandir(unsigned long long*& vetor, long& l) //recebe uma referência de ponteiro e de long
{
	l *= 2; //duplica a variável de tamanho do vetor
	unsigned long long* w = new unsigned long long[l]; //cria um vetor temporário
	for (long i = 0; i < (l / 2); i++) { w[i] = vetor[i]; }; //copia os dados do vetor antigo para o temporário
	delete[] vetor; //exclui o vetor original
	vetor = w; //recria e atribui o vetor de volta
}

