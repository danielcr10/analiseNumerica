double Euler (double t0, double t1, double h, double y0, double (*f) (double t, double y)){
  //t0 - tempo inicial
  //t1 - tempo final
  //h - passo de integração
  //y(t0) - valor inicial
  //f(t,y(t)) - função derivada
  //y(t1) - retorno do valor no tempo final  
  
  double taux, yaux;
  
  taux = t0;
  yaux = y0;
  for(i = 1, n){
    y = y + h*f(t,y)
    t=t+h
  }
  return y;
    
}

double EulerAdapt (double t0, double t1, double h0, double y0, double (*f) (double t, double y), double tol){

}
