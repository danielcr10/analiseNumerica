#include <stdio.h>
#include <math.h>

double derivada (double (*f) (double x), double x, double h){
  return (f(x + h) - f(x - h)) / 2 * h;
}

double h_otimo (double (*f) (double x), double (*fl) (double x), double x){

  int i = 1;
  double menorErro, h;
  double valorH, erro, valorflX;

  valorflX = fl(x);
  valorH = pow(10.0, -1 * i);
  menorErro = fabs(valorflX - derivada( f, x, h ) );

  for(i = 2; i < 13; i++){
    //printf("Executou i = %d\n", i);
    h = pow(10.0, -1 * i);
    erro = fabs(valorflX - derivada( f, x, h ) );
    if( erro < menorErro ){
      menorErro = erro;
      valorH = h;
    }  
  }
  return valorH;
}

double simpson (double (*f) (double), double a, double b, int n){
  double hPassos, resul = 0, h, m;
  hPassos = (b - a)/n;
  
  for(int i = 0; i < n; i++)
  {
    b = a + hPassos;
    m = (a + b)/2;
    h = b - a;
    resul += h/6 * ( f(a) + 4*f(m) + f(b) );
    a = b;
  }
  return resul;  
}

double pontomedio (double (*f) (double), double a, double b, int n){
  double hPassos, m, h, resul = 0;
  hPassos = (b - a)/n;
  
  for(int i = 0; i < n; i++){
    b = a + hPassos;
    m = (a + b)/2;
    h = b - a;
    resul += h * f(m);
    a = b;
  }
  return resul;
}
