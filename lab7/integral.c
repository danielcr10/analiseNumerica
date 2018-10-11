#include <stdio.h>
#include <math.h>
//Erro da função é a diferença entre a recebida(analitica) e a numerica
//uma função diferenca que a variação do h faz.

double derivada (double (*f) (double x), double x, double h){
  return (f(x + h) - f(x - h)) / 2 * h;
}

double h_otimo (double (*f) (double x), double (*fl) (double x), double x){
  //nao precisa da formula so erro, so compara os resultados para diferentes h resposta deu 10^⁻6 no x=0
  double menorErro = 1000;
  double valorH, erro;
  
  for(int i = 1; i < 13; i++){
    erro = fabs(fl(x) - derivada( f, x, (double)pow(10, -i) ) );  //otimizar fl(x) é sempre o msm
    if( erro < menorErro ){
      menorErro = erro;
      valorH = pow(10, -i);
    }  
  }
  return valorH;
}

double simpson (double (*f) (double), double a, double b, int n){
  //valor pra simpson
}

double pontomedio (double (*f) (double), double a, double b, int n){

}

int main(){
  return 0;
}
