#ifndef COLLATZ_H
#define COLLATZ_H

class Collatz {
	private: 
		bool _verbose;

		int _inicioACalcular;
		int _finalACalcular;
		
		int _numeroInicialAtual;

		int _maiorNumero;
		int _maiorSequencia;

		bool isPar(int numero);
		long int calculaProximoNumero(long int numero);
		void criaSequencia();
		void criaSerieSequencias();
	public:
		Collatz(int inicio, int fim, bool verbose);
		int GetNumeroMaiorSequencia();
		int GetQtdMaiorSequencia();


};

#endif
