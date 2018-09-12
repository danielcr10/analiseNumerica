#include "raiz.h"

double f(double x)
{
	double result;
	result = cos(x) - x*x*x + x;
	return result;
}

double h(double m)
{
	return (9.8*m/15)*(1-exp(-(15/m)*9))-35;
}

int main()
{
	int bissecaoInt, bissecao2Int;
	double r, r3;

	int iqiInt, iqi2Int;
	double r2, r4;

	//Calculo da f(x) = cos(x) - x^3 + x com Bisseção
	bissecaoInt = bissecao (0, 2, 6, f, &r);
	printf("Numero de interaçoes f(x) bissecao: %d\n", bissecaoInt);
	printf("Resultado: %.15f\n", r);


	//Calculo da f(x) = cos(x) - x^3 + x com IQI
	iqiInt = IQI(0, 1, 2, 6, f, &r2);
	printf("\nNumero de interaçoes f(x) IQI: %d\n", iqiInt);
	printf("Resultado IQI: %.15f\n\n", r2);

	//Calculo da massa do paraquedista com Bisseção
	bissecao2Int = bissecao (0, 300, 6, h, &r3);
	printf("Numero de interaçoes paraquedista bissecao: %d\n", bissecao2Int);
	printf("Resultado: %.15f\n", r3);

	iqi2Int = IQI(0, 1, 2, 6, h, &r4);
	printf("\nNumero de interaçoes paraquedista IQI: %d\n", iqi2Int);
	printf("Resultado IQI: %.15f\n", r4);

  return 0;  
}
