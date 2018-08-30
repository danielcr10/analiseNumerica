#include <stdio.h>
#include <math.h>

//a e b = intervalo de busca
//p = precisão testar com p=15
//f = f(x)
//r = endereço da raiz
int bissecao (double a, double b, int p, double (*f) (double x), double* r)
{
  int interacoes=0;
  double erro, c;
  double erroesp, tolerancia;
  
  tolerancia = pow(10, -(double)p);
  erroesp = 0.5*tolerancia;
  erro = (b - a)/2;
  while(erro > erroesp) //nao sei se aqui realmete é erro
  {
    c = (a + b)/2;
    if(f(c) < tolerancia ) //testar a precisao aqui, vai avaliar todas as vezes?
    {
      break;
    }
    if(f(a)*f(c) < 0)
    {
      b = c;
    }
    else
    {
      a = c;
    } 
    erro /= 2;
    interacoes++;
  }
  
  *r = c;
  //erro = (b - a)/pow(2,interacoes+1);
  return interacoes;
}

int IQI (double x0, double x1, double x2, int p, double (*f) (double x), double* r)
{
  
}



//minimizar o numero de chamadas da fnç metodo aberto tm que botar limite

