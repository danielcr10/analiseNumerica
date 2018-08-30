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
  double erro, fx0, fx1, fx2, detAc, detA;
  int interacoes = 0;
  
  erroEsp = 0.5*pow(10,-(double)p);
  
  while(abs(f(x2)) > erroEsp)
  {
    fx0 = f(x0);
    fx1 = f(x1);
    fx2 = f(x2);
    
    fx02 = (fx0*fx0);
    fx12 = (fx1*fx1);
    fx22 = (fx2*fx2);
    
    detA = fx02 * fx1 * 1 + fx0 * 1 * fx22 + fx12 * fx2 * 1 - (fx22 * fx1 * 1 + fx2 * 1 *  fx02 + fx0 * fx12 * 1);
    
    detAc = fx02 * fx1 * x2 + fx0 * x1 * fx22 + fx12 * fx2 * x0 - (fx22 * fx1 * x0 + fx2 * x1 *  fx02 + fx0 * fx12 * x2);
    
    c = detAc/detA;
    x0 = x1;
    x1 = x2;
    x2 = c;
    interacoes++;
  }
  *r = c;
  
  return interacoes;
}



//minimizar o numero de chamadas da fnç metodo aberto tm que botar limite

