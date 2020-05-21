#include <collatz.h>
#include <stdio.h>

bool Collatz::isPar(int numero) {
	return (numero % 2 == 0);
}

long int Collatz::calculaProximoNumero(long int numero) {
	return this->isPar(numero) ? (numero / 2) : (3 * numero + 1);
}

void Collatz::criaSequencia() {
	int tamanhoSequencia = 1;

	long int n = this->_numeroInicialAtual;

	//Sem necessidade de calcular o n como 1, pois já sabemos que o resultado é 1.
	while (n != 1 && n > 0) {
		n = this->calculaProximoNumero(n);
		tamanhoSequencia++;

		if (tamanhoSequencia > this->_maiorSequencia)
		{
			this->_maiorSequencia = tamanhoSequencia;
			this->_maiorNumero = this->_numeroInicialAtual;
		}

			
		if (this->_verbose)
			printf("Numero da sequencia atual: %d \n", n);
	}
}

void Collatz::criaSerieSequencias() {
	
	//Inicializando para não ocorrer erros caso só avaliarmos de 1 até 1.
	this->_maiorSequencia = 1;
	this->_maiorNumero = 1;

	for (int n = this->_inicioACalcular; n <= this->_finalACalcular; n++) {
		this->_numeroInicialAtual = n;

		if (this->_verbose)
			printf("Criando serie de sequencias para o numero inicial %d \n", this->_numeroInicialAtual);

		this->criaSequencia();	
	}
}

Collatz::Collatz(int inicio, int fim, bool verbose) {
	this->_inicioACalcular = inicio;
	this->_finalACalcular = fim;

	this->_verbose = verbose;

	this->criaSerieSequencias();
}

int Collatz::GetNumeroMaiorSequencia() {
	return this->_maiorNumero;
}

int Collatz::GetQtdMaiorSequencia() {
	return this->_maiorSequencia;
}
