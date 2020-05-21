#include <stdio.h>
#include <collatz.h>

#include <iostream>

const int minThisTest = 0;
const int maxThisTest = 10000000;

bool validarInput(int input) {
	bool tmpReturn = input > minThisTest && input < maxThisTest;
	if (!tmpReturn)
		printf("O número deve ser maior que %d e menor que %d. \n", minThisTest, maxThisTest);

	return tmpReturn;
}

int main() {

	int numeroInicio;
	int numeroFinal;

	printf("Adicione o número inicial para os cálculos:");
	std::cin >> numeroInicio;

	if (!validarInput(numeroInicio)) 
		return 0;

	printf("Adicione o número final para os cálculos:");
	std::cin >> numeroFinal;

	if (!validarInput(numeroFinal)) 
		return 0;

	Collatz* collatz = new Collatz(numeroInicio, numeroFinal, false);

	int numeroMaiorSequencia = collatz->GetNumeroMaiorSequencia();
	int qtdMaiorSequencia = collatz->GetQtdMaiorSequencia();

	printf("O número da maior sequência é: %d, cujo tamanho é de %d números. \n", numeroMaiorSequencia, qtdMaiorSequencia);
	return 0;
}
