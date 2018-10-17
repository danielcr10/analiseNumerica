#include <stdio.h>
#include <math.h>
#include "integral.h"

double f(double x);
double fLinha(double x);
double f1(double x);
double f2(double x);
double f3(double x);

int main(){

  //2 - (a)
  double hOtimo;
  hOtimo = h_otimo(f, fLinha, 5); 
  printf("%f\n", hOtimo);

  double resultado;

	//2 - (b)
	//Integral 1 - Simpson
	resultado = simpson(f1, 0, 4, 16);
	printf("Integral 1, n = 16 (Simpson): %f\n", resultado);
	resultado = simpson(f1, 0, 4, 32);
	printf("Integral 1, n = 32 (Simpson): %f\n", resultado);

	//Integral 1 - Médio
	resultado = pontomedio(f1, 0, 4, 16);
	printf("Integral 1, n = 16 (Médio): %f\n", resultado);
	resultado = pontomedio(f1, 0, 4, 32);
	printf("Integral 1, n = 32 (Médio): %f\n", resultado);

	//Integral 2 - Simpson
	resultado = simpson(f2, 1, 3, 16);
	printf("Integral 2, n = 16 (Simpson): %f\n", resultado);
	resultado = simpson(f2, 1, 3, 32);
	printf("Integral 2, n = 32 (Simpson): %f\n", resultado);

	//Integral 2 - Médio
	resultado = pontomedio(f2, 1, 3, 16);
	printf("Integral 2, n = 16 (Médio): %f\n", resultado);
	resultado = pontomedio(f2, 1, 3, 32);
	printf("Integral 2, n = 32 (Médio): %f\n", resultado);

	//Integral 3 - Simpson
	resultado = simpson(f3, 0, M_PI, 16);
	printf("Integral 3, n = 16 (Simpson): %f\n", resultado);
	resultado = simpson(f3, 0, M_PI, 32);
	printf("Integral 3, n = 32 (Simpson): %f\n", resultado);

	//Integral 3 - Médio
	resultado = pontomedio(f3, 0, M_PI, 16);
	printf("Integral 3, n = 16 (Médio): %f\n", resultado);
	resultado = pontomedio(f3, 0, M_PI, 32);
	printf("Integral 3, n = 32 (Médio): %f\n", resultado);

	return 0;
}

double f(double x){
  return cos(x) - 2*sin(x);
}

double fLinha(double x){
  return -sin(x) - 2*cos(x);
}

double f1(double x) {
	return x / sqrt(pow(x, 2) + 9);
}

double f2(double x) {
	return pow(x, 2) * log(x);
}

double f3(double x) {
	return pow(x, 2) * sin(x);
}
